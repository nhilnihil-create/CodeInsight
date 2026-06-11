#include "bits/stdc++.h"

#define ll long long
#define ull unsigned long long
#define ld long double

#define tiii tuple < int, int, int >
#define pii pair < int, int >
#define pll pair < ll, ll >
#define pci pair < char, int >
#define psi pair < string, int >
#define pis pair < int, string >

#define vi vector < int >
#define vd vector < double >
#define vld vector < ld >
#define vll vector < ll >
#define vs vector < string >
#define vc vector < char >
#define vpi vector < pii >
#define vpll vector < pll >
#define vpis vector < pis >

#define pb push_back
#define mt make_tuple
#define gt0 get < 0 >
#define gt1 get < 1 >
#define gt2 get < 2 >

#define pi acos(-1)

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int n, m, sum;
vi edges[maxn];
bool vis[maxn];

void dfs(int u)
{
    vis[u] = 1;
    sum++;

    for(auto v : edges[u]){
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fast;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;

        cin >> u >> v;

        edges[u].pb(v);
        edges[v].pb(u);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            sum = 0;
            dfs(i);
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}
