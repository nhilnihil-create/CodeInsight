#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(std::string S)
{
    bool flag=true;
    for(unsigned int i=0;i<S.size();i+=2)
        if(S[i]=='h'&&S[i+1]=='i')
            continue;
        else
        {
            flag=false;
            break;
        }            
    if(flag)    cout<<YES<<endl;
    else    cout<<NO<<endl;
}

int main()
{
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
