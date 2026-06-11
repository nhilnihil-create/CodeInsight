#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
ll dp[3005][3005], a[3005];
ll mod = 998244353;
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("BONUS.INP", "r")){
                freopen("BONUS.INP", "r", stdin);
                freopen("BONUS.OUT", "w", stdout);
        }
        ll n, s;
        cin >> n >> s;
        for (int i = 1; i <= n; i++){
                cin >> a[i];
        }
        dp[0][0] = 1;
        for (int i = 0; i < n; i++){
                for (int j = 0; j <= s; j++){
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 2) % mod;
                        if ((j + a[i + 1]) <= s){
                                dp[i + 1][j + a[i + 1]] = (dp[i + 1][j + a[i + 1]] + dp[i][j]) % mod;
                        }
                }
        }
        cout << dp[n][s];
}
