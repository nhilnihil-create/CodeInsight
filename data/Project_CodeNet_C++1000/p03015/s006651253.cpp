#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

ll dp[1000010][2];

int main()
{
    string s; cin >> s;
    ll n = s.size();
    dp[0][0] = 1;
    rep(i,n){
        rep(j,2){
            int nd = s[i] - '0';
            if(j == 0){
                if(nd == 0) dp[i+1][j] += dp[i][j];
                else{
                    dp[i+1][1] += dp[i][j];
                    dp[i+1][0] += 2*dp[i][j];
                }
            }else{
                dp[i+1][j] += 3*dp[i][j];
            }
            dp[i+1][j] %= mod;
        }
    }
    cout << (dp[n][0]%mod + dp[n][1]%mod)%mod << endl;
}
