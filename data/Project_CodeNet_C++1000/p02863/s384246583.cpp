#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

using P = pair<int, ll>;
ll dp[3005][3005];
int main() {
    int N, T;
    cin >> N >> T;
    vector<P> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        ll b;
        cin >> a >> b;
        A[i] = P(a, b);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        for (int t = 0; t < T; t++) {
            chmax(dp[i + 1][min(t + A[i].first, T)], dp[i][t] + A[i].second);
            chmax(dp[i + 1][t], dp[i][t]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        chmax(ans, dp[i + 1][T]);
    }
    cout << ans << endl;
}
