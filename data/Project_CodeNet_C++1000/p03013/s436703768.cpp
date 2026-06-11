#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, m;
    cin >> n >> m;

    bool isbroken[n] = {};
    rep(i, m){
        ll a;
        cin >> a;
        a--;
        isbroken[a] = true;
    }

    ll dp[n+1];
    if(isbroken[0])dp[0] = 0;
    else dp[0] = 1;

    if(isbroken[1])dp[1] = 0;
    else dp[1] = dp[0] + 1;

    for(ll i = 2; i < n; ++i){
        if(isbroken[i]){
            dp[i] = 0;
            continue;
        }
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }

    cout << dp[n-1] << endl;
}