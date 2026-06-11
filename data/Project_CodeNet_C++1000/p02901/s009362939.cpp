#include <bits/stdc++.h>
#define clr(i, j)     memset(i, j, sizeof(i))
using namespace std;
 
#define ll long long
ll n,m;
ll dp[1000][(1 << 13)];
ll a[10000];
 ll armask[10000];
 ll msk;
ll solve(ll i,ll mask){
    
    if(mask==(1ll << n) - 1){
        return 0;
    }if(i==m){
        return 1e9;
    }ll &ret=dp[i][mask];
    if(ret!=-1){
        return ret;
    }
   ret=min( solve(i+1,mask|armask[i])+a[i] ,solve(i+1,mask));
   return ret;
}

int main()
{
    //cout<<pow(2,12);
   cin>>n>>m;
   for(int i=0;i<n;i++){
       msk|=(1<<i);
   }
   clr(dp,-1);
    for(ll i=0;i<m;i++){
       ll b;
        cin>>a[i]>>b;
        ll mask=0;
       for(ll j=0;j<b;j++){
           ll x;
           cin>>x;
           mask|=(1<<(x-1));
       }armask[i]=mask;
    }
    ll ans=solve(0,0);
    if(ans==1e9){cout<<-1;}else{cout<<ans;}
   
}