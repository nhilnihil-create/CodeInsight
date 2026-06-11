#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 2e18;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> H(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> H[i];
    vector<vector<int>> dp(N + 1, vector<int>(N - K + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - K; j++) {
            for (int k = 0; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0LL, H[i] - H[k]));
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= N; i++) ans = min(ans, dp[i][N - K]);
    cout << (ans == INF ? 0 : ans) << endl;
}