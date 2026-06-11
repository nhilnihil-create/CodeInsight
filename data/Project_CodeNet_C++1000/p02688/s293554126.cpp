#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define N 100010
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>flags(n+1);
    for(int i=0;i<k;i++)
    {
        int d;
        cin>>d;
        for(int j=0;j<d;j++)
        {
            int z;
            cin>>z;
            flags[z]=1;
        }
        
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(flags[i]==0)
        count++;
    }
    cout<<count<<endl;
    
}

int main()
{
    solve();
}