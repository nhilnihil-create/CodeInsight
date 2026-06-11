#include <bits/stdc++.h>

#define ll long long
#define lst(x) x.size()-1
#define ld long double
#define pr pair<ll,ll>
#define loop(i, n) for(ll i=0 ; i<n ; ++i)
#define rep(i, x, n) for(ll i=x ; i<=n ; ++i)
#define iteloop(type, data, name, it) for(type<data>::iterator it=name.begin() ;it!=name.end() ; ++it)

using namespace std;

const ll N = 3e2 + 5, M = 1e6+5 , C=1e3+5, MOD = 1e9 + 7, OO = 1e9+5;
ll arr[N],n,k;
ll memo[N][N][N];


ll dp(int i=1,int lft=k,int lst=0){
    if(i>=n)return 0;
    ll &res=memo[i][lft][lst];
    if(~res)return res;

    ll x=max(0ll,arr[i]-arr[lst]);
    res=x + dp(i+1,lft,i);
    if(lft>0){
        // try back
        res = min(res, dp(i + 1, lft - 1 ,lst ));

        // try front
        x=max(0ll,arr[i+1]-arr[lst]);
        res=min(res , dp(i+1,lft-1,i+1) + x);
    }
    return res;
}
int main() {
    cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
  //  freopen("in.txt", "rt", stdin);
    // freopen("in.txt", "wt" , stdout);
#endif
    cin>>n>>k;
    rep(i,1,n){
        cin>>arr[i];
    }
    n++;
    memset(memo,-1,sizeof(memo));
    cout<<dp()<<endl;
}
