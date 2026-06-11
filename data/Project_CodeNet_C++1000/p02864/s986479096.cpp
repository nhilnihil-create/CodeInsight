#include <bits/stdc++.h>

#define ll long long



using namespace std;

const int N_MAX = 302;
const ll INF = 1000000000000001;

int n, k;

int h[N_MAX];

ll dp[N_MAX][N_MAX][N_MAX];

vector <pair <int, int> > v;

int pos[N_MAX];

ll aib1[N_MAX][N_MAX][N_MAX];
ll aib2[N_MAX][N_MAX][N_MAX];

void update1 (int i, int j, int pos, ll val)
{
    pos++;
    for(int x = pos; x <= n + 1; x += x & (-x))
        aib1[i][j][x] = min(aib1[i][j][x], val);
}
void update2 (int i, int j, int pos, ll val)
{
    pos++;
    for(int x = pos; x >= 1; x -= x & (-x))
        aib2[i][j][x] = min(aib2[i][j][x], val);
}

ll query1 (int i, int j, int pos)
{
    pos++;
    ll ans = INF;
    for(int x = pos; x >= 1; x -= x & (-x))
        ans = min(ans, aib1[i][j][x]);
    return ans;
}
ll query2 (int i, int j, int pos)
{
    pos++;
    ll ans = INF;
    for(int x = pos; x <= n + 1; x += x & (-x))
        ans = min(ans, aib2[i][j][x]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i];
        v.push_back(make_pair(h[i], i));
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++)
        pos[v[i - 1].second] = i;
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= k; j++)
            for(int x = 0; x <= n + 1; x++)
                aib1[i][j][x] = aib2[i][j][x] = INF;
    update1(0, 0, 0, 0);
    update2(0, 0, 0, 0);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int x = 0; x <= n; x++)
            {
                dp[i][j][x] = INF;
                if(j == 0 && x != i)
                    continue;
                if(j > 0)
                    dp[i][j][x] = dp[i][j - 1][x];
                if(x == i)
                {
                    dp[i][j][x] = min(dp[i][j][x], query1(i - 1, j, pos[x]));
                    dp[i][j][x] = min(dp[i][j][x], query2(i - 1, j, pos[x]) - h[x]);
                }
                else
                {
                    dp[i][j][x] = min(dp[i][j][x], query1(i - 1, j - 1, pos[x]));
                    dp[i][j][x] = min(dp[i][j][x], query2(i - 1, j - 1, pos[x]) - h[x]);
                }
                update1(i, j, pos[x], dp[i][j][x]);
                update2(i, j, pos[x], dp[i][j][x] + h[x]);
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i <= n; i++)
        ans = min(ans, dp[n][k][i] + h[i]);
    cout << ans << "\n";
    return 0;
}
