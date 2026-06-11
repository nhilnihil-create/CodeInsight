#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

struct DSU{
    vector<int> p, sz;
    DSU(int n){
        p = sz = vector<int>(n,1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int get(int a){
        return p[a] = (p[a] == a ? a : get(p[a]));
    }
    void join(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    DSU d(n);
    int ans = 0;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        d.join(a, b);
    }
    for (int i = 0; i<  n; ++i){
        ans = max(ans, d.sz[d.get(i)]);
    }
    cout << ans << '\n';
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}

