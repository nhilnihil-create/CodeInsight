#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;


int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> key(m);
    vector<ll> cost(m);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        ll res = 0;
        rep(i,b){
            ll c;
            cin >> c;
            res += 1<<(c-1);
        }
        key[i] = res;
        cost[i] = a;
    }
    vector<ll> dp(1<<n,LINF);
    dp[0] = 0;
    rep(bit,1<<n){
        rep(i,m){
            dp[bit|key[i]] = min(dp[bit|key[i]],dp[bit] + cost[i]);
        }
    }
    if(dp[(1<<n) -1] ==LINF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;
    return 0;
}