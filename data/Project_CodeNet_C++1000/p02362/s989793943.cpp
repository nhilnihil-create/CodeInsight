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


int V, E, r;
int dist[1005];
vector<vector<pii>> g;

int main() {
    cin >> V >> E >> r;
    g.resize(V);
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].pb(make_pair(d, t));
    }

    rep(i, V) dist[i] = INF;
    dist[r] = 0;

    rep(i, V) {
        rep(u, V) {
            for (pii edge: g[u]) {
                int cost = edge.first;
                int v = edge.second;
                if (dist[u] != INF && dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;

                    if (i == V - 1) {
                        cout << "NEGATIVE CYCLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    rep(i, V) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

