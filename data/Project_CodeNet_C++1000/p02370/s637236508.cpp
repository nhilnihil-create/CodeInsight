#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

struct Edge{
  int to, cost;

  Edge(int t, int c = 0): to(t), cost(c)
  {}
  bool operator>(const Edge& rhs) const{
	return cost > rhs.cost;
  }
  bool operator<(const Edge& rhs) const{
	return cost < rhs.cost;
  }

};
using Graph =  vector< vector<Edge> >;

// calc topological sort
// O(V+E)
bool topo_sort(const Graph& G, VI& order){
  int N = G.size();
  VI color(N, 0);
  
  function<bool(int)> visit = [&](int v)->bool{
	color[v] = 1;
	for(const auto& e: G[v]){
	  if(color[e.to] == 2) continue;
	  if(color[e.to] == 1) return false;
	  if(!visit(e.to)) return false;
	}
	order.push_back(v);
	color[v] = 2;
	return true;
  };

  for(int u=0;u<N;++u)
	if(!color[u] && !visit(u))
	  return false;
  reverse(begin(order), end(order));
  return true;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;
  Graph G(V);
  REP(i,E){
	int s, t;
	cin >> s >> t;
	G[s].EB(t);
  }
  VI order(V);
  topo_sort(G, order);
  REP(i,V) cout << order[i] << endl;

  return 0;
}