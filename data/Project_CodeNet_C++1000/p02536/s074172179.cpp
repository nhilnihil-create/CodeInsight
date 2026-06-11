#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define PI 2 * acos(0)
#define ones(n) __builtin_popcount(n)
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 9000000
#define debug(x) cerr << #x << " = " << x << '\n';
#define LOOP printf("LOOP!!")
#define READ freopen("input.txt", "r", stdin)
#define PRINT freopen("output.txt", "w", stdout);
#define print(a, b) printf("Case %d: %lld\n", a, b)
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
using namespace std;
const int VAL = 2e5 + 10;
vector<int> v[VAL];

bool vis[VAL];

void dfs(int n)
{

    vis[n] = true;

    for (int i = 0; i < v[n].size(); i++)
    {
        int next = v[n][i];

        if (!vis[next])
            dfs(next);
    }
}

/************MAIN_FUNCTION**********/
int main(int argc, char *argv[])
{
    ///Disjoint set union
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {

        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i), c++;

    cout << c - 1 << '\n';
    return 0;
}