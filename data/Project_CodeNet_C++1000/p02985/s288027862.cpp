#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> seen(n);
    vector<int> depth(n);
    vector<int> ith(n);
    queue<int> que;
    que.push(0);
    seen[0] = true;
    depth[0] = 0;
    while (que.size()) {
        int u = que.front();
        que.pop();
        int i = 0;
        for (auto v: g[u]) {
            if (!seen[v]) {
                seen[v] = true;
                depth[v] = depth[u] + 1;
                ith[v] = i;
                i++;
                que.push(v);
            }
        }
    }

    ll ans = 1;
    rep(i, n) {
        ans *= max(0, k - min(2, depth[i]) - ith[i]);
        ans %= MOD;
    }
    cout << ans << endl;
}
