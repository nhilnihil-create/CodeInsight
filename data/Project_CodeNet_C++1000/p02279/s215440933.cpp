#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


int n;
Graph G,Grev;

int dfs(int v){
  // Grevの一番奥がparent
  if (Grev[v].size() == 0) return v;
  return dfs(Grev[v][0]);
}

void depths(vector<int> &depth, int v, int rank){
  for (int nv : G[v]){
    depth[nv] = rank + 1;
    depths(depth, nv, rank+1);
  }
}

int main() {
  cin >>n;
  G.assign(n, vector<int>());
  Grev.assign(n, vector<int>());
  rep(i, n){
    int v; cin >>v;
    int k; cin >>k;
    rep(j, k){
      int c; cin >>c; G[v].push_back(c); Grev[c].push_back(v);
    }
  }
  int parent = dfs(0);
  vector<int> depth(n, -1); depth[parent] = 0;
  depths(depth, parent, 0);

  rep(i, n){
    cout <<"node " <<i <<": parent = ";
    if (i == parent) cout <<-1;
    else cout <<Grev[i][0];
    cout <<", depth = " <<depth[i] <<", ";
    if (i == parent) cout <<"root, [";
    else if (G[i].size() == 0) cout <<"leaf, [";
    else cout <<"internal node, [";
    for (int j=0; j<G[i].size(); j++){
      if (j > 0) cout <<", ";
      cout <<G[i][j];
    }
    cout <<"]" <<endl;
  }
}
