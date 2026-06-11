#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
const ll mod = 1000000000 + 7;
#define NMAX 100010

ll dp[NMAX][13];

void init(){
    rep(i, 0, NMAX) rep(j, 0, 13) dp[i][j] = 0;
}

int main(){

    init();

    string s;
    cin >> s;
    ll n = s.size();
    reverse(s.begin(), s.end());

    ll pw = 1;
    dp[0][0] = 1;
    rep(i, 0, n) {
        if(s[i] == '?') {
            rep(j, 0, 13) {
                rep(k, 0, 10) {
                    // j に k*pw を足した時の遷移
                    ll nj = (j + k * pw) % 13;
                    dp[i+1][nj] += dp[i][j];
                    dp[i+1][nj] %= mod;
                }
            }
        } else {
            rep(j, 0, 13) {
                ll now = s[i] - '0';
                ll nj = (j + now * pw) % 13;
                dp[i+1][nj] += dp[i][j];
                dp[i+1][nj] %= mod;
            }
        }
        pw *= 10;
        pw %= 13;
    }

    cout << dp[n][5] << endl;
    return 0;
}