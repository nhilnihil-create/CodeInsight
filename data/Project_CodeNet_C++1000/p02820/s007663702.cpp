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
    int N, K;
    cin >> N >> K;
    int R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    auto dp = make_vec(N + 1, 3, 0LL);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(i - K >= 0 && k == j)
                    continue;
                int point = 0;
                if(k == 0) {
                    if(T[i] == 's')
                        point = R;
                } else if(k == 1) {
                    if(T[i] == 'r')
                        point = P;
                } else if(k == 2) {
                    if(T[i] == 'p')
                        point = S;
                }
                dp[i][k] =
                    max(dp[i][k], (i - K >= 0 ? dp[i - K][j] : 0) + point);
            }
        }
    }
    ll res = 0;
    for(int i = N - 1; i >= N - K; i--) {
        ll tmp = 0;
        for(int j = 0; j < 3; j++) {
            tmp = max(tmp, dp[i][j]);
        }
        res += tmp;
    }
    cout << res << endl;
}