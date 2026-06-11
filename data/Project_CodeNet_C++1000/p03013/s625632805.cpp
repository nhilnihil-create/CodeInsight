#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll MOD = 1e9 + 7;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> dp(N + 1, -1);
    vector<ll> a(M);
    for (int i = 0; i < M; i++)
    {
        cin >> a[i];
        dp[a[i]] = 0;
    }

    dp[0] = 1;
    

    for (int i = 1; i <= N; i++)
    {
        if (dp[i] == 0)
        {
            continue;
        }
        if (i == 1)
        {
            dp[i] = dp[i - 1];
            continue;
        }
        
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    
    cout << dp[N] << endl;
  return 0;
}
