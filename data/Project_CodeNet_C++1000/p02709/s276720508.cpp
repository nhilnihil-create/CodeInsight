#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

ll dp[2010][2010];

int main() {
    int N;
    cin >> N;
    V<int> A(N);
    rep(i, N) cin >> A[i];
    V<pii> B(N);
    rep(i, N) B[i] = mp(A[i], i);
    sort(ALL(B));
    reverse(ALL(B));

    for (int l = 0; l <= N; ++l) {
        for (int r = 0; r < N - l; ++r) {
            int use = l + r;
            chmax(dp[l + 1][r],
                  dp[l][r] + abs(l - B[l + r].se) * (ll)B[l + r].fi);
            chmax(dp[l][r + 1],
                  dp[l][r] + abs(N - 1 - r - B[l + r].se) * (ll)B[l + r].fi);
        }
    }
    ll ans = 0;
    rep(i, N + 1) { chmax(ans, dp[i][N - i]); }
    cout << ans << endl;

    return 0;
}