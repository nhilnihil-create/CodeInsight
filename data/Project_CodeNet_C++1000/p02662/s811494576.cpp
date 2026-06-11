#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A.at(i);

    vector<vector<ll>> dp(N, vector<ll>(S+1, 0));
    dp[0][0] = 2;
    if(A[0] <= S) dp[0][A[0]] = 1;

    for(int i=1; i<N; i++)
    {
        for(int j=0; j<S+1; j++)
        {
            dp[i][j] += 2*dp[i-1][j];
            dp[i][j] %= mod;
            if(j + A[i] <= S)
            {
                dp[i][j+A[i]] += dp[i-1][j];
                dp[i][j+A[i]] %= mod;
            }
        }
    }
    cout << dp[N-1][S] << endl;

    return 0;
}
