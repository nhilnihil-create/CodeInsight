#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
int g[15][15];
int main(){
  int n;
  cin >> n;
  rep(i,n)rep(j,n)g[i][j] = -1;
  rep(i,n){
    int m;
    cin >> m;
    rep(j,m){
      int a,x;
      cin >> a >> x;
      a--;
      g[i][a] = x;
    }
  }
  int ans = 0;
  rep(i,1 << n){
    vector<int> d(n);
    rep(j,n)if(i >> j & 1)d[j] = 1;
    bool ok = true;
    rep(j,n){
      if(d[j]){
        rep(k,n){
          if(g[j][k] == -1)continue;
          if(g[j][k] != d[k])ok = false;
        }
      }
    }
    if(ok)ans = max(ans,__builtin_popcount(i));
  }
  cout << ans << endl;
  return 0;
}
