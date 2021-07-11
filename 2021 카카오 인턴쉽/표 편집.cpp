#include <string>
#include <vector>
#include <set>
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    set<int> row;
    stack<int> st;
    set<int>::iterator it;
    for(int i=0; i<n; i++)
        row.insert(i);

    it=row.begin();
    for(int i=0; i<k; i++)
        it++;
    

    for(int i=0; i<cmd.size(); i++)
    {
        if(cmd[i][0]=='U')
        {
            int number=stoi(cmd[i].substr(2));
            for(int j=0; j<number; j++)
                it--;
        }
        else if(cmd[i][0]=='D')
        {
            int number=stoi(cmd[i].substr(2));
            for(int j=0; j<number; j++)
                it++;
        }
        else if(cmd[i][0]=='C')
        {
            st.push(*it);
            it = row.erase(it);
            if(it==row.end())
                it--;
        }
        else if(cmd[i][0]=='Z')
        {
            row.insert(st.top());
            st.pop();
        }
    }

    it=row.begin();
    for(int i=0; i<n; i++)
    {
        if(it!=row.end() && i==*it)
        {
            answer+='O';
            it++;
        }
        else
        {
            answer+='X';
        }
    }

    return answer;
}

int main(void)
{
    int n=8;
    int k=2;
    string c[9]={"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    vector<string> cmd;
    for(int i=0; i<9; i++)
        cmd.push_back(c[i]);
    cout<<solution(n, k, cmd);
}
