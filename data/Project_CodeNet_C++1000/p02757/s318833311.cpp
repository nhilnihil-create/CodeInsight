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

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    if(P == 2 || P == 5) {
        ll ans = 0;
        rep(i, N) {
            ll d = S[i] - '0';
            if(d % P == 0) ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    
    vll cnt(P, 0);
    ll now = 0;
    ll beki = 1;
    for(ll i = N-1; i >= 0; i--) {
        ll d = S[i] - '0';
        now += d * beki;
        now %= P;
        cnt[now]++;
        beki = beki * 10 % P;
    }

    ll ans = cnt[0];
    for(auto x : cnt) if(x >= 2) ans += x * (x-1) / 2;
    cout << ans << endl;
}
