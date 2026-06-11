#include "bits/stdc++.h"
using namespace std;
typedef  long long ll;
const ll MAXN=1e3+100,OO=1e16;
ll dp[MAXN][(1<<12)],n,a[MAXN],m,b[(1<<12)];
ll solve(int idx,ll msk){
    if(__builtin_popcount(msk)==n)return 0;
    if(idx==m)return OO;
    ll &ret=dp[idx][msk];
    if(~ret)
        return ret;
    ret=solve(idx+1,msk);
    ret=min(ret,solve(idx+1,msk|b[idx])+a[idx]);
    return ret;
}
int main(){
ll c,x; cin>>n>>m;
 for(int i=0;i<m;i++){
  cin>>a[i]>>c;
  while(c--)
      cin>>x,x--,b[i]+=(1LL<<x);
 }
 memset(dp,-1, sizeof(dp));
 ll ans=solve(0,0);
 if(ans>=OO)cout<<-1;
 else cout<<ans;
}