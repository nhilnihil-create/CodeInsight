#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

ll MOD = 1e9 + 7;

int main(){
    int N, M;
    cin >> N >> M;
    int s[N], t[M];
    for(int i = 0; i < N; i++) cin >> s[i];
    for(int i = 0; i < M; i++) cin >> t[i];

    vector<vector<ll>> dp(N, vector<ll>(M, 0LL));
    vector<vector<ll>> sum(N + 1, vector<ll>(M + 1, 0LL));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(s[i] == t[j]){
                dp[i][j] = sum[i][j] + 1;
                dp[i][j] %= MOD;
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + dp[i][j] + MOD;
                sum[i + 1][j + 1] %= MOD;
            }
            else{
                dp[i][j] = 0;
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + MOD;
                sum[i + 1][j + 1] %= MOD;
            }
        }
    }

    ll ans = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ans += dp[i][j];
            ans %= MOD;
        }
    }

    //debug
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << ans << endl;
    return 0;
}