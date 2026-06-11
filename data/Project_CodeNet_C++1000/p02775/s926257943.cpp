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
// const ll MOD = 998244353;
const double PI=3.14159265358979323846;



int main() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<ll>> dp(n+10, vector<ll>(2));
    dp[0][1] = 1;
    rp(i, 0, n) {
        int m = s[i] - '0';
        dp[i+1][0] = min(dp[i][1] + (10 - m), dp[i][0] + m);
        dp[i+1][1] = min(dp[i][1] + (10 - m - 1), dp[i][0] + (m+1));
    }
    cout << dp[n][0] << endl;
    return 0;
}
