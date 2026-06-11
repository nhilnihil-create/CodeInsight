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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll dp[2200][2200];
int main() {
    ll N; cin >> N;
    vpll A;
    rep(i, N) {
        ll a; cin >> a;
        A.emplace_back(a, i);
    }
    sort(A.begin(), A.end(), greater<pll>());

    ll cnt;
    ll ans = 0;
    rep(l, N) rep(r, N) {
        if(l+r == N) {
            chmax(ans, dp[l][r]);
            break;
        }
        cnt = l + r;
        chmax(dp[l+1][r], dp[l][r] + abs(A[cnt].second - l) * A[cnt].first);
        chmax(dp[l][r+1], dp[l][r] + abs(A[cnt].second - (N-1-r)) * A[cnt].first);
    }
    cout << ans << endl;
}
