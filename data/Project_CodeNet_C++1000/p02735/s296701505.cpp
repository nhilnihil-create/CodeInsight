#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ll,ll> pll;

const int N = 1e2+2;
const int INF = 1e9;
int n, m;
int dr[2] = {0,1};
int dc[2] = {1,0};
int dp[N][N];
char ar[N][N];

bool inRange(int r, int c)
{
    return r >= 1 && r <= n && c >= 1 && c <= m;
}

int solve(int r, int c)
{
    if (r == n && c == m)
        return ar[r][c] == '#';
    if (dp[r][c] != -1)
        return dp[r][c];
    int ret = INF;
    for (int i = 0; i < 2; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!inRange(nr,nc))
            continue;
        ret = min(ret, solve(nr,nc) + (ar[r][c] == '#' && ar[nr][nc] == '.')); 
    }
    return dp[r][c] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ar[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << solve(1,1) << '\n';
    return 0;
}