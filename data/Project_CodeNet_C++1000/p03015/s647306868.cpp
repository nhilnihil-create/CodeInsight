#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = sz(s);
    vvi dp(n+1, vi(2, 0));
    dp[0][0] = 1;
    rep(i, n) {
        {   // a+b = 0
            if (s[i] == '0') {
                dp[i+1][0] = dp[i][0];
                dp[i+1][1] = dp[i][1];
            } else {
                dp[i+1][1] = (dp[i][0] + dp[i][1]) % mod;
            }
        }
        {   // a+b = 1
            if (s[i] == '0') {
                dp[i+1][1] += dp[i][1] * 2 % mod;
                dp[i+1][1] %= mod;
            } else {
                dp[i+1][0] += dp[i][0] * 2 % mod;
                dp[i+1][0] %= mod;
                dp[i+1][1] += dp[i][1] * 2 % mod;
                dp[i+1][1] %= mod;
            }
        }
    }
    int ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << endl;
}