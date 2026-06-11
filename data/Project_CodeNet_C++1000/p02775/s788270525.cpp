#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

int dp[1000010][2];
signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    string N;
    cin >> N;
    dp[0][0] = 0;
    dp[0][1] = 1;
    REP(i, N.size())
    {
        int c = N[i] - '0';
        dp[i + 1][0] = dp[i][0] + c;
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1 + c);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (10 - c));
        if (c == 9)
        {
            dp[i + 1][1] = dp[i][0] + 1;
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1 + 1);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1]);
        }
        else
        {
            dp[i + 1][1] = dp[i][0] + (c + 1);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1 + c + 1);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (10 - c) - 1);
        }
    }
    cout << dp[N.size()][0] << endl;

    return 0;
}