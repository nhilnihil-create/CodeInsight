#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

static const ll mod = 1000000007;
int dp[100010][2];

int main(void){
    string s;
    cin >> s;

    // 桁DP
    int n = s.length();
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        // a + b のi桁目 = 0 とする場合((a, b) = (0, 0))
        {
            if(s[i] == '1'){
                // dp[i + 1][0]は、この場合はない
                // 前の状態からは両方ともdp[i + 1][1]へ遷移可能
                dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
            }
            else{
                // 
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = dp[i][1];
            }
        }

        // a + b のi桁目 = 1 とする場合((a, b) = (1, 0) or (0, 1))
        {
            if(s[i] == '1'){
                dp[i + 1][0] += dp[i][0] * 2 % mod;
                dp[i + 1][0] %= mod;
                dp[i + 1][1] += dp[i][1] * 2 % mod;
                dp[i + 1][1] %= mod;
            }
            else{
                dp[i + 1][1] += dp[i][1] * 2 % mod;
                dp[i + 1][1] %= mod;
            }
        }
    }
    int ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << endl;
    return 0;
}