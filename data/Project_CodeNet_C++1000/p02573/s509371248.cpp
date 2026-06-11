#include <bits/stdc++.h>

#define endl '\n'
#define PB push_back
#define PF push_front
#define MP make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 14;

vector<vector<int>> G;
vector<bool> used;


int dfs(int v) {
    int res = 1;
    used[v] = 1;
    for (auto to : G[v]) {
        if (!used[to]) {
            res += dfs(to);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); //cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    used.resize(n);
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].PB(b);
        G[b].PB(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i));
    }

    cout << ans;
    return 0;
} 
