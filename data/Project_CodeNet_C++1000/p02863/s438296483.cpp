#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;

lint powint(lint x, lint y){
    int ret = 1;
    for (int i=0; i < y; i++) ret *= x;
    return ret;
};

vector<int> dx = {1, 0, 0, -1, 1, 1, -1, -1};
vector<int> dy = {0, -1, 1, 0, 1, -1, 1, -1};

lint powmod(lint a, lint b, lint mod = 1000000007) {
   lint res = 1;
   for (a %= mod; b; a = a * a % mod, b >>= 1)
     if (b & 1) res = res * a % mod;
   return res;
 }

int main() {
    lint n, t; cin >> n >> t;
    vlint a(n+1), b(n+1);
    rep(i, n){
        cin >> a[i+1]; cin >> b[i+1];
    }

    vlint2 dp1(n+5, vlint(t));
    vlint2 dp2(n+5, vlint(t));
    For(i, 1, n+1){
        rep(j, t){
            if (j - a[i] >= 0){
                dp1[i][j] = max(dp1[i - 1][j - a[i]] + b[i], dp1[i - 1][j]);
            }
            else{
                dp1[i][j] = dp1[i - 1][j];
            }
        }
    }
    for (int i = n+1; 1 < i; i--){
        rep(j, t){
            if (j - a[i - 1] >= 0){
                dp2[i-1][j] = max(dp2[i][j - a[i - 1]] + b[i - 1], dp2[i][j]);
            }
            else{
                dp2[i-1][j] = dp2[i][j];
            }
        }
    }

    lint ans = 0;
    For(i, 1, n+1){
        rep(j, t){
            ans = max(ans, dp1[i - 1][j] + dp2[i+1][t-1 - j] + b[i]);
        }
    }
    cout << ans << endl;
}

