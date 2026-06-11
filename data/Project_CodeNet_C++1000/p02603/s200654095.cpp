#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> dp(N + 1);
    // dp[i]:=i日目終了時の最大のお金
    dp[0] = 1000;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j]);
            for(int k = j + 1; k <= i; k++) {
                ll kabu = dp[j] / A[k - 1];
                ll rest = dp[j] % A[k - 1];
                for(int l = k + 1; l <= i; l++) {
                    dp[i] = max(dp[i], kabu * A[l - 1] + rest);
                }
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}