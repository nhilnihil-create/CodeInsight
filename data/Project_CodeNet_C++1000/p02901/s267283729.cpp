#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 5, mod = 1e9 + 7;

int dp[8192][N], n, m;
pair<int, int> a[N];

int solve(int mask, int i)
{
    if (i == m)
        return mask == ((1 << n) - 1)? 0: 1e9;
    if (dp[mask][i] != -1)
        return dp[mask][i];
    int ans = solve(mask, i + 1);
    if (mask != ((1 << n) - 1))
        ans = min(ans, solve((mask | a[i].second), i + 1) + a[i].first);
    return dp[mask][i] = ans;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first;
        int y;
        cin >> y;
        a[i].second = 0;
        while (y--)
        {
            int x;
            cin >> x;
            a[i].second |= (1 << (x - 1));
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(0, 0);
    if (ans > 1e8)
        cout << -1;
    else
        cout << ans;
    return 0;
}