/* ** *** Be Name Khoda *** ** */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
bool mark[maxn];
vector <int> v[maxn];
void dfs(int a)
{
    mark[a] = 1;
    for (int u : v[a])
        if (!mark[u]) dfs(u);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;i++)
    {
        if (!mark[i]) dfs(i),ans++;
    }
    cout << ans - 1;
    return 0;
}