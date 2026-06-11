#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,i;
    map<int,int>mp;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    cin>>a;
    mp[a]=i;
    }
    for(i=1;i<=n;i++)
    {
        cout<<mp[i]<<" ";
    }
}