#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> stair(N+1, 1);
    for (int i = 0; i < M; i++)
    {
        int pos;
        cin >> pos;
        stair[pos] = 0;
    }

    vector<ll> dp(N+1, 0);
    dp[0] = 1;
    for (int now = 0; now < N; now++)
    {
        for (int next = now+1; next <= min(N, now+2); next++)
        {
            if(stair[next] > 0){
                dp[next] += dp[now];
                dp[next] %= mod;
            }
        }
        
    }

    cout << dp[N] << endl;
    
    return 0;
}
