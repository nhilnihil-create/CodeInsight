#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define square(x) pow(x,2.0)
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define max_queue(x) priority_queue<x>
#define min_queue(x) priority_queue<x, vector<x>, greater<x>>
#define big_sort(v) sort(all(v), [](int a, int b) { return a > b; })//大きい順にソート
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
using vd = vector<long double>;
#define co(x) cout << x << endl;
#define cins(n,v) rep(i,n){cin >> v.at(i);}
#define couts(v) rep(i,v.size()){cout << v.at(i) << endl;}
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
int main() {
  int n,k,l=0,r=1e9;
  cin >> n>>k;
  vi v(n);
  cins(n,v);
  while (r-l > 1) {
    int x = (l+r)/2;
    auto f = [&](int x) {
      ll now = 0;
      rep(i,n) now += (v[i]-1)/x;
      return now <= k;
    };
    if (f(x)) r = x; else l = x;
  }
  cout << r << endl;
  return 0;
}
