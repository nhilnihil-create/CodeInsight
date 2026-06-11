#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    int ans=0;
    while(n>0)
    {
        n/=r;
        ans++;
    }
    cout<<ans<<"\n";
}