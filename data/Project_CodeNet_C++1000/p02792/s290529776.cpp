#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

ll digit(ll n) {
    ll ret = 0;
    while(n > 0) {
        n /= 10;
        ret++;
    }
    return ret;
}


int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vvll cnt(10, vll(10, 0));
    for(ll i = 1; i <= N; i++) {
        ll last = i % 10;
        ll first = i;
        rep(j, digit(i)-1) first /= 10;
        cnt[first][last]++;
    }

    ll ans = 0;
    for(ll i = 1; i <= 9; i++) {
        for(ll j = 1; j <= 9; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
}
