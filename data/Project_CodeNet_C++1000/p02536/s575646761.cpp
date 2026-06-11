#include <bits/stdc++.h>
using namespace std;
#define f(i, k, n) for (int i = k; i < n; i++)
#define r(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define tr(it, v) for (auto &it : v)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << ","<< #z << "=" << z << endl
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
// =================

const int mod = 1e9;
const int N = 3e5 + 1;

vi g[N];
int A[N];

void impgraph(int n, int m)
{
    int i=0, u, v;
    while (m--)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par)
{
    A[u]=1;
    for (int v : g[u])
    {
        if (A[v])
        {
            continue;
        }
        dfs(v, par);
    }
}

void solve()
{
    int n,m; cin>>n>>m;
    impgraph(n,m);
    dfs(1,0);
    int cnt=0;
    f(i,1,n+1) {
        if(!A[i]) {
            dfs(i,0);
            cnt++;
        }
    }
    cout<<cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();
    return 0;
}