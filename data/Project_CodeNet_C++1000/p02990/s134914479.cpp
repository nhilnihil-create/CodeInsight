#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<vector<ll> > dp(2001,vector<ll>(2001));
    for (int i = 0; i <= 2000; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 2; i <= 2000; i++){
        for (int j = 1; j <= i - 1; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
        }
    }
    for (ll i = 1; i <= K; i++){
        ll ans = ((dp[N - K + 1][i] * dp[K - 1][i - 1]) % 1000000007);
        cout << ans << endl;
    }
}

