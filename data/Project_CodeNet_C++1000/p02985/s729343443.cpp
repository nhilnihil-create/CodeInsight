#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

struct Edge{
  int from;
  int to;
  long cost;
};

long k;

void dfs(vector<vector<Edge>> &Graph, vector<long> &num, int v, int pv){
  long cnt = k - 2 + (pv == -1);
  for(Edge ed : Graph.at(v)){
    int nv = ed.to;
    if(pv == nv) continue;
    //cout << nv << endl;
    num.at(nv) = cnt;
    cnt--;
    dfs(Graph,num,nv,v);
  }
}

int main(){
  long n;
  cin >> n >> k;
  vector<vector<Edge>> Graph(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    //cout << a << " " << b << endl;
    Graph.at(a).push_back(Edge{a,b,1});
    Graph.at(b).push_back(Edge{b,a,1});
  }
  vector<long> num(n);
  num.at(0) = k;
  dfs(Graph, num, 0, -1);
  long ans = 1;
  rep(i,n){
    //cout << num[i] << endl;
    ans *= num[i];
    ans %= MOD;
  }
  cout << ans << endl;
}