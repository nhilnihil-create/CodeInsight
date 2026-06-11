#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool visited[10010];
vector<vector<int>> g;
stack<int> st;

void topological_sort(int i) {
    visited[i] = true;
    for (int j: g[i]) {
        if (!visited[j]) topological_sort(j);
    }
    st.push(i);
}

int main() {
    int V, E; cin >> V >> E;
    g.resize(V);
    rep(i, E) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
    }

    rep(i, V) {
        if (!visited[i]) topological_sort(i);
    }

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

