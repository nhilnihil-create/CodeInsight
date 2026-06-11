#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, k, mod=1e9+7, fac[200009], dp[100009], fac2[200009];
vector<int> v[100009];
int solve(int node, int p)
{
    int &ans=dp[node];
    if(ans!=-1)
        return ans;
    ans=1;
    int sz=v[node].size();
    if(node==1)
    {
        sz++;
        ans=fac[max(0,k-sz+1)];
        for(auto i : v[node])
            ans=(1LL*ans*solve(i,node))%mod;
        return ans;
    }
    sz--;
    if(sz==0)
    return 1;
    ans=fac2[max(0,k-2-sz+1)];
    for(auto i : v[node])
        if(i!=p)
            ans=(1LL*ans*solve(i,node))%mod;
    return ans;
}
int main()
{
    IO
    cin>>n>>k;
    for(int i=1; i<n; i++)
    {
        int x, y ;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    fac[k]=k;
    for(int i=k-1; i>=1; i--)
        fac[i]=(1LL*fac[i+1]*i)%mod;
    if(k>2)
    {
        fac2[k-2]=k-2;
        for(int i=k-3; i>=1; i--)
            fac2[i]=(1LL*fac2[i+1]*i)%mod;
    }
    memset(dp,-1,sizeof dp);
    cout<< solve(1,0);
}
