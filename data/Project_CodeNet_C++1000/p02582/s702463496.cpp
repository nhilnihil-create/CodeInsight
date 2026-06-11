#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int res=0;
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='R')
        {
            c++;
            res=max(res,c);
        }
        else
        {
            c=0;
        }
        
    }
    cout<<res<<endl;
}