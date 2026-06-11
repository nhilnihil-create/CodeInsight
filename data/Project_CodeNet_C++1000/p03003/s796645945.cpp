#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[2003][2003];

int main()
{
    int n, m;
    cin >> n >> m;
    int s[2003], t[2003];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = 1;
            else if(s[i - 1] == t[j - 1]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + MOD - dp[i - 1][j - 1]) % MOD;
        }
    }
    cout << dp[n][m] << endl;
}
