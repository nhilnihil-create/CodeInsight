#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, D, A; cin >> N >> D >> A;
    vector<pll> p;
    rep(i, N) {
        ll x, h;
        cin >> x >> h;
        p.emplace_back(x, h);
    }
    sort(p.begin(), p.end());

    vll s(N+1, 0);
    ll ans = 0, right = 0;
    rep(i, N) {
        p[i].second -= s[i];
        while(right < N && p[right].first <= p[i].first + 2*D) right++;
        if(p[i].second > 0) {
            ll num = (p[i].second + A - 1) / A;
            ans += num;
            s[i] += num * A;
            s[right] -= num * A;
        }
        s[i+1] += s[i];
    }
    cout << ans << endl;
}
