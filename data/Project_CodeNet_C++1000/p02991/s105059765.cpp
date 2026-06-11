#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 4e4+5;
int n, m;
vector<vector<int>> v;
int bfs(int src, int dst)
{
    int ans[n + 1][3];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            ans[i][j] = 1e9;
    queue<pair<int, int>> q;
    q.push({src, 0});
    ans[src][0] = 0;
    while(!q.empty())
    {
        int node = q.front().F, md = q.front().S;
        q.pop();
        for (auto to : v[node])
        {
            int nxt_md = (md + 1) % 3;
            if (ans[to][nxt_md] == 1e9)
            {
                q.push({to, nxt_md});
                ans[to][nxt_md] = ans[node][md] + 1;
            }
        }
    }
    return (ans[dst][0] == 1e9 ? -1 : ans[dst][0] / 3);
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    int s, t;
    cin >> s >> t;
    cout << bfs(s, t);
    return 0;
}