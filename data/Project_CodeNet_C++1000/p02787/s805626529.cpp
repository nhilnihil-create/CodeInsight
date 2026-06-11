#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
template <class T> vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
template <typename T> struct edge {
    int to;
    T cost;
    edge(int t, T c) : to(t), cost(c) {}
};
template <typename T> using WGraph = vector<vector<edge<T>>>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    ll H, N;
    cin >> H >> N;
    vector<ll> A(N), B(N);
    rep(i, N) { cin >> A[i] >> B[i]; }
    auto dp = make_vec(N + 1, H + 1, LINF);
    rep(i, N) dp[i][0] = 0;
    // dp[i][j]:=i-1番目の魔法まで見て、ダメージをj与えるときの最小
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= H; j++) {
            dp[i + 1][min(H, j + A[i])] =
                min(dp[i + 1][min(H, j + A[i])], dp[i][j] + B[i]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
        for(int j = 0; j <= H; j++) {
            dp[i + 1][min(H, j + A[i])] =
                min(dp[i + 1][min(H, j + A[i])], dp[i + 1][j] + B[i]);
        }
    }
    cout << dp[N][H] << endl;
}