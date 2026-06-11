#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*typedef vector<int> vi;
typedef vector<ll> vl;*/
vector<vector<int>>v(200002);
bool visited[200002] = { false };
int c = 0;
void dfs(int i, int n)
{
    if (i > n || visited[i])
        return;
    visited[i] = true;
    c++;
    for (int j = 0; j < v[i].size(); j++)
    {
        dfs(v[i][j], n);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        c = 0;
        if (!visited[i])
        {
            dfs(i + 1, n);
        }
        res = max(c, res);
    }
    cout << res << endl;
}
