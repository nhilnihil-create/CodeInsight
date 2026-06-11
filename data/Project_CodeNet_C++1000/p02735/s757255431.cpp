#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    REP(i, H)
    {
        cin >> s[i];
    }

    ll dp[H][W];
    REP(i, H)
    {
        REP(j, W)
        {
            dp[i][j] = LONG_MAX;;
        }
    }

    dp[0][0] = s[0][0] == '.' ? 0 : 1;
    REP(i, H)
    {
        REP(j, W)
        {
            if (i - 1 >= 0)
            {
                if (s[i - 1][j] == '.' && s[i][j] == '#')
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                }
            }
            if (j - 1 >= 0)
            {
                if (s[i][j - 1] == '.' && s[i][j] == '#')
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                }
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}
