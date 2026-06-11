#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 60; //10e18+10e17ちょっとくらい
const int MOD = 1000000007;
const int MAX_N = 200100;

int dp[2020][2020];
signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N;
    cin >> N;

    vector<pair<int, int>> q;
    REP(i, N)
    {
        int tmp;
        cin >> tmp;
        q.emplace_back(make_pair(tmp, i));
    }
    sort(ALL(q));
    reverse(ALL(q));
    int ans = 0;
    REP(i, N)
    {
        for (int l = 0; l <= i; l++)
        {
            int r = i - l;
            dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + q[i].first * abs(q[i].second - l));
            dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + q[i].first * abs(q[i].second - (N - 1 - r)));
            ans = max(ans, dp[l + 1][r]);
            ans = max(ans, dp[l][r + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}