#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    int x=s.size();
    int ans=0;
    for(int i=0;i<x;i++)
    {
        if(s[i]!=t[i])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
