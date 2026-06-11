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

// struct Edge{
//   int to,color,id;
//   Edge(int to,int id,int color): to(to),id(id),color(color) {}
// };

int main() {
  int N;cin>>N;
  vector<vector<int>> tree(N,vector<int>());
  int K = 0;
  map<P,int> dic;
  rep(i,N-1) {
    int a,b;cin>>a>>b;
    a--;b--;
    dic[P(a,b)] = i;
    dic[P(b,a)] = i;
    tree[a].push_back(b);
    tree[b].push_back(a);
    K = max(K,(int)tree[a].size());
    K = max(K,(int)tree[b].size());
  }
  vector<int> col(N-1,0);
  queue<int> qu;
  qu.push(0);
  vector<bool> done(N,false);
  done[0] = true;
  vector<int> parent(N,-1);
  while(!qu.empty()) {
    int now = qu.front();
    qu.pop();
    int cnt = 1;
    for(auto nxt : tree[now]) {
      if(!done[nxt]) {
	done[nxt] = true;
	parent[nxt] = now;
	if(cnt == col[dic[P(now,parent[now])]]) {
	  cnt++;
	}
	col[dic[P(now,nxt)]] = cnt;
	cnt++;
	qu.push(nxt);
      }
    }
  }
  cout<<K<<endl;
  rep(i,N-1) cout<<col[i]<<endl;
}
