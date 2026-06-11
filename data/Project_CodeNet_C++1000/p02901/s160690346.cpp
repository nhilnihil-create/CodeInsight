#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, price[1009], dp[1009][4500];
string s;
vector<int> keys[1009];
int solve(int i, int msk)
{
    if(i==m)
    {
        if(msk==(1<<n)-1)
            return 0 ;
        return 2e8;
    }
    int &ans=dp[i][msk];
    if(ans!=-1)
        return ans;
    ans=solve(i+1,msk);
    for(auto j : keys[i])
        msk|=(1<<j);
    ans=min(ans,solve(i+1,msk)+price[i]);
    return ans;
}
int main()
{
    IO
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>price[i];
        int sz;
        cin>>sz;
        while(sz--)
        {
            int x;
            cin>>x;
            x--;
            keys[i].push_back(x);
        }
    }
    memset(dp,-1,sizeof dp);
    int ans=solve(0,0);
    if(ans>1e8)
        ans=-1;
    cout<<ans;

}
