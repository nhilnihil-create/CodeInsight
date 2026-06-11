#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
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

    string s;
    cin >> s;

    ll dp[n+2];
    rep(i, n+2)dp[i] = INF;
    dp[0] = 0;
    rep(i, n+1){
        if(s[i] == '1')continue;
        for(ll j = 1; j <= min(i, m); ++j)dp[i] = min(dp[i], dp[i-j]+1);
    }

    if(dp[n] >= INF){
        cout << -1 << endl;
        return 0;
    }

    vector<ll> ans;
    ll p = n;
    while(p > 0){
        ll mv;
        for(ll i = 1; i <= min(p, m); ++i){
            if(dp[p-i] == dp[p]-1)mv = i;
        }
        ans.insert(ans.begin(), mv);
        p -= mv;
    }

    for(ll i : ans)cout << i << " ";
}