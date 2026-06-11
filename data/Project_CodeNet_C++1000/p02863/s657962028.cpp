#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> food;
    rp(i, 0, n) {
        int a, b; cin >> a >> b;
        food.emplace_back(a, b);
    }
    sort(food.begin(), food.end());
    vector<vector<int>> dp(n+1, vector<int>(t+2, -INT_MAX));
    dp[0][0] = 0;
    rp(i, 0, n) {
        int a = food[i].second;
        int b = food[i].first;
        rp(j, 0, t) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j + b >= t) chmax(dp[i+1][t], dp[i][j] + a);
            else chmax(dp[i+1][j+b], dp[i][j] + a);
        }
        chmax(dp[i+1][t], dp[i][t]);
    }
    int res = 0;
    rp(i, 0, t+1) chmax(res, dp[n][i]);
    cout << res << endl;
    return 0;
}
