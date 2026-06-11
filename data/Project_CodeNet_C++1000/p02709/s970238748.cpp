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
const int INF = 1e9;
// const int MOD = 1e9 + 7;
using P = pair<ll, ll>;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<P> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        B.at(i) = P(A[i], i);
    }

    sort(B.begin(), B.end(), greater<P>());
    vector<vector<ll>> dp = make_vec<ll>(N + 1, N + 1);  // x人を左端、y人を右端に寄せる
    for (int x = 0; x < N; x++) {
        for (int y = 0; x + y < N; y++) {
            chmax(dp[x + 1][y], dp[x][y] + B[x + y].first * abs(B[x + y].second - x));
            chmax(dp[x][y + 1], dp[x][y] + B[x + y].first * abs(B[x + y].second - (N - 1 - y)));
        }
    }
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        chmax(ans, dp[i][N - i]);
    }
    cout << ans << endl;
}
