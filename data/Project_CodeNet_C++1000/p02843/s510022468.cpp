#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(ll i = 0; i <= n; i++)
#define REp(i,n) for(ll i = 1; i < n; i++)
#define REP(i,n) for(ll i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

set<int> can;

void f(int n, V<int> &m) {
  if(n > 100000) return;
  can.insert(n);
  rep(i,6) {
    int nx = n + m[i];
    if(can.find(nx) == can.end()) f(nx,m);
  }
}

int main(){
  int x;
  cin >> x;
  V<int> m = {100,101,102,103,104,105,106};
  f(0,m);
  for(int i : can) {
    if(i == x) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}