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
    int N;cin>>N;
    vector<vector<int>> tbl(N,vector<int>(N));
    int cnt = 0;
    rep(i,N-1) {
        for (int j = i+1;j<N;j++) {
            tbl[i][j] = cnt;
            tbl[j][i] = cnt;
            cnt++;
        }
    } 
    vector<vector<int>> a(N,vector<int>(N-1));
    rep(i,N) {
        rep(j,N-1) {
            int b;cin>>b;
            b--;
            a[i][j] = b;
        }
    }
    vector<vector<int>> graph(N*(N-1)/2,vector<int>());
    vector<int> indeg(N*(N-1)/2,0);
    rep(i,N) {
        rep(j,N-2) {
            graph[tbl[i][a[i][j]]].push_back(tbl[i][a[i][j+1]]);
            indeg[tbl[i][a[i][j+1]]]++;
        }
    }
    vector<int> depth(N*(N-1)/2,0);
    queue<int> qu;
    vector<int> topo;
    rep(i,N*(N-1)/2) {
        if(indeg[i]==0) {
            qu.push(i);
            topo.push_back(i);
        }
    }
    int mx = 0;
    while(!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for(auto nxt : graph[now]) {
            if(indeg[nxt]!=0) {
                indeg[nxt]--;
                depth[nxt] = max(depth[nxt],depth[now]+1);
                mx = max(mx,depth[nxt]);
                if(indeg[nxt]==0) {
                    qu.push(nxt);
                    topo.push_back(nxt);
                }
            }
        }
    }
    if(topo.size()!=N*(N-1)/2) {
        cout<<-1<<endl;
    } else {
        cout<<mx+1<<endl;
    }

}