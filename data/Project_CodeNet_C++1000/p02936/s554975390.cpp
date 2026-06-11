#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;
const ll INF = 10010010010010010;

vector<int> E[200005];
ll ans[200005];

void dfs(int par, int to, ll score) {
    ans[to] += score;
    for (auto& nx : E[to]) {
        if (nx != par) dfs(to, nx, ans[to]);
    }
}

int main() {
    int n,m,a,b,p; cin >> n >> m;
    rep(i,n-1) {
        cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    rep(i,n) ans[i] = 0;
    ll x;
    rep(i,m) {
        cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(-1,0,0);
    rep(i,n) {
        printf("%lld ", ans[i]);
    }
    printf("\n");

    return 0;
}
