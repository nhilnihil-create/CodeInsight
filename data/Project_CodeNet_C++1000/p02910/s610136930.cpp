#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int flag=0;
    for(int i=0;i<s.size();i++)
    {
        if((i+1)&1)
        {
            if(s[i]=='L')
            {
                flag++;
                break;
            }
        }
        else
        {
            if(s[i]=='R')
            {
                flag++;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}