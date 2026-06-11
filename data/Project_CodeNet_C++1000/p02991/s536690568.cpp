#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
    int N,M;cin>>N>>M;
    vector<vector<int>> g(N,vector<int>());
    rep(i,M) {
        int u,v;cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
    }
    int S,T;cin>>S>>T;
    S--;T--;
    vector<vector<ll>> dist(N,vector<ll>(3,-1));
    queue<P> qu;
    qu.push(P(S,0));
    dist[S][0] = 0;
    while(!qu.empty()) {
        int v = qu.front().first,three = qu.front().second;
        qu.pop();
        for(auto nxt: g[v]) {
            if(dist[nxt][(three+1)%3] == -1) {
                dist[nxt][(three+1)%3] = dist[v][three] + 1;
                qu.push(P(nxt,(three+1)%3));
            }
        }
    }
    if(dist[T][0] == -1) {
        cout<<-1<<endl;
    } else {
        cout<<dist[T][0]/3<<endl;
    }
}