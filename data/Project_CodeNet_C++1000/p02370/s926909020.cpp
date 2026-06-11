#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------
vector<vector<int>> g(10001);
vector<bool> seen(10001, false);
vector<int> ans;

void dfs(int v)
{
    if (seen[v])
    {
        return;
    }
    seen[v] = true;
    for (auto next : g[v])
    {
        dfs(next);
    }
    ans.push_back(v);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
    }
    for (int i = 0; i < V; i++)
    {
        dfs(i);
    }
    reverse(ALL(ans));
    for (auto a : ans)
    {
        cout << a << endl;
    }
}
