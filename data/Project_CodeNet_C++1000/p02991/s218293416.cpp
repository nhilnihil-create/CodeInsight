#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template < typename T > string tost( const T& n ) { ostringstream stm; stm << n; return stm.str();}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;

vector<int> G[100050];

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N,M;
cin >> N >> M;

rep(i,M) {
    int u,v;
    cin >> u >> v;
    --u; v--;
    G[u].push_back(v);
}
int s,t;
cin >> s >> t;
--s; --t;

vvl dist(N, vl(3, -1));
dist[s][0] = 0;
queue<pii> que;
que.push({s, 0});

while(!que.empty()) {
    pii cur = que.front();
    que.pop();
    int v = cur.fi;
    int r = cur.se;
    for(auto nv : G[v]) {
        int nr = (r + 1) % 3;
        if(dist[nv][nr] == -1) {
            dist[nv][nr] = dist[v][r] + 1;
            que.push({nv, nr});
        }
    }
}

if(dist[t][0] == -1) cout << -1 << endl;
else cout << dist[t][0] / 3 << endl;

return 0;
}