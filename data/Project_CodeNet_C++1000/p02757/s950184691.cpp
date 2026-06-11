#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int N, P;
    string S;
    cin >> N >> P >> S;

    ll res = 0;
    if (P == 2) {
        for (int i=0; i<N; ++i) if ((int)(S[i]-'0') % 2 == 0) res += i+1;
    } else if (P == 5) {
        for (int i=0; i<N; ++i) if (S[i] == '0' || S[i] == '5') res += i+1;
    } else {
        vector<ll> dp(N+1);
        ll ten = 1;
        for (int i=N-1; i>=0; --i) {
            dp[i] = (dp[i+1] + ten * (ll)(S[i]-'0')) % P;
            (ten *= 10) %= P;
        }
        map<ll, ll> mp;
        for (int i=0; i<N+1; ++i) ++mp[dp[i]];
        for (auto p : mp) res += p.second * (p.second-1) / 2;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
