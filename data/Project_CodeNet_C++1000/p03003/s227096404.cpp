#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

const int mod = 1000000007;
ll dp[2020][2020];
ll sum[2020][2020];

int main(void){
    int n, m;
    cin >> n >> m;
    vector<ll> s(n);
    vector<ll> t(m);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < m; i++){
        cin >> t[i];
    }

    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));

    dp[0][0] = 1; // 空文字どうしなので
    // sum[0][0] = 1;(冗長)

    // 絶対ここだわ、nまでしか足してなかった。
    for(int i = 0; i <= 2020; i++){sum[0][i] = 1; sum[i][0] = 1;}

    ll ret = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = sum[i-1][j-1]%mod;
            }
            sum[i][j] = (sum[i][j-1] + sum[i-1][j] + mod - sum[i-1][j-1] + dp[i][j])%mod;
        }
    }
    cout << sum[n][m]%mod << endl;
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
