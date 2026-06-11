#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,a,ans=0;
    cin>>n>>x;
    int d[n+1];
    d[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        d[i+1]=d[i]+a;
    }
    for(int i=0;i<=n;i++)
    {
        if(d[i]<=x)
        ans++;
        else
        break;
    }
    cout<<ans<<"\n";
}