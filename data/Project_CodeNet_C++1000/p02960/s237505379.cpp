#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

ll dp[100010][13];

int main()
{
    string s; cin >> s;
    dp[0][0] = 1;
    int n = s.size();
    rep(i,n) rep(j,13){
        if(s[i] == '?'){
            rep(k,10){
                dp[i+1][(j*10+k)%13] += dp[i][j];
                dp[i+1][(j*10+k)%13] %= mod;
            }
        }else{
            int nd = s[i] - '0';
            dp[i+1][(j*10+nd)%13] += dp[i][j];
            dp[i+1][(j*10+nd)%13] %= mod;
        }
    }
    cout << dp[n][5] << endl;
}