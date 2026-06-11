#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<vector<vector<bool>>> dp(N+1, vector<vector<bool>>(4, vector<bool>(1000, false)));
    dp[0][0][0] = true;
    for(int i=0; i<N; i++)
    {
        int num = S[i] - '0';
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<1000; k++)
            {
                if(j<3 && k%10 == num)
                {
                    dp[i+1][j+1][k] = dp[i][j][k/10];
                }
                dp[i+1][j][k] = (dp[i+1][j][k] || dp[i][j][k]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<1000; i++)
    {
        if(dp[N][3][i])
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}