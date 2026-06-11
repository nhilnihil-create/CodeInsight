// includes
#include <bits/stdc++.h>

// macros
#define ll long long int
#define pb emplace_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define FI first
#define SE second
using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}

struct Graph{
  int n;
  vector<vector<int> > edge;
  vector<int> in_deg;
  Graph(int n_){
    n = n_;
    edge.resize(n);
    in_deg.resize(n, 0);
  }
  void adde(int at, int to){
    edge[at].push_back(to);
    in_deg[to]++;
  }
  vector<int> topological_sort(){
    stack<int> st;
    for(int i = 0; i < n; i++){
      if(in_deg[i] == 0)st.push(i);
    }
    vector<int> res;
    while(st.size()){
      int at = st.top(); st.pop();
      res.push_back(at);
      for(int j: edge[at]){
        in_deg[j]--;
        if(in_deg[j] == 0)st.push(j);
      }
    }

    return res;
  }
};

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Graph graph(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    graph.adde(a, b);
  }
  auto v = graph.topological_sort();
  rep(i, sz(v))cout << v[i] << endl;
	return 0;
}

