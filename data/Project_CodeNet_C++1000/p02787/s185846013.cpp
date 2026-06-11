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
    int h, n; cin >> h >> n;
    vector<vector<int>> dp(n+1, vector<int>(h+1, 1e9));
    dp[0][0] = 0;
    rp(i, 1, n+1) {
        int a, b; cin >> a >> b;
        rp(j, 0, h+1) {
            dp[i][j] = min(dp[i-1][j], dp[i][max(0, j-a)] + b);   
        }
    }
    cout << dp[n][h] << endl;
    return 0;
}
