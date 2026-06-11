#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
void dfs(vector<vector<int>> &g, vector<int> &c, int v, int p){
  for(auto nv:g[v]){
    if(nv==p)continue;
    c[nv]+=c[v];
    dfs(g,c,nv,v);
  }
  return;
}
int main() {
  cout << fixed << setprecision(10);
  int n,q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> count(n,0);
  rep(i,q){
    int p,x;
    cin >> p >> x;
    p--;
    count[p]+=x;
  }
  dfs(g,count,0,-1);
  rep(i,n){
    cout << count[i] << " ";
  }
  cout << endl;
}
