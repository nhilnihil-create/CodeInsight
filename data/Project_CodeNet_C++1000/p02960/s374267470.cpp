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

int mypow(int X, int n) {  // 繰り返し２乗法　計算量log(n)
    if(n == 0) return 1;
    int Y = mypow(X, n/2);
    if(n % 2 == 1) return X * Y % 13 * Y % 13;
    else return Y * Y % 13;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    vector<vector<ll>> dp(100010, vector<ll>(13));
    dp[0][0] = 1;
    rp(i, 0, n) {
        char c = s.at(i);
        int p = mypow(10, i);
        if(c == '?') {
            rp(m, 0, 10) {
                rp(j, 0, 13) {
                    dp[i+1][(j+p*m)%13] = (dp[i+1][(j+p*m)%13]+dp[i][j])%MOD;
                }
            }
        }
        else {
            int m = c - '0';
            rp(j, 0, 13) {
                dp[i+1][(j+p*m)%13] = (dp[i+1][(j+p*m)%13]+dp[i][j])%MOD;
            }
        }
    }
    // rp(i, 0, n+1) {
    //     rp(j, 0, 13) {
    //         printf("%lld / ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    cout << dp[n][5] << endl;
    return 0;
}
