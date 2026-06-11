//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 1e5 + 5;
const int M = 17 + 5;
const int W = 1000 + 5;
const int OO = 2e9;
const int mod = 1e9 + 7;

int n,k,a,b,vis[N];
vector<int> g[N];

int mul(int x, int y) {

    return (1LL*x*y)%mod;

}

int dfs(int u, int par) {

    vis[u] = 1;

    int ret = 1, l = k - 1 - par;

    for(auto v:g[u]) {

        if(!vis[v]) {
            ret = mul(mul(ret,l--),dfs(v,1));
        }

    }

    return ret;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    cout << mul(k,dfs(1,0)) << '\n';

    return 0;
}