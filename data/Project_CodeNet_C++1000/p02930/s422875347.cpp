#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  
  vector<vector<int>> a(n, vector<int>(n, 0)), res;
  vector<int> fi(n);
  rep(i, n) fi[i] = i;
  res.push_back(fi);
  int level = 1;
  while (res.size() < n) {
    vector<vector<int>> nxt;
    rep(i, res.size()) {
      vector<int> v = res[i];
      if (v.size() == 1) {
        nxt.push_back(v);
        continue;
      }
      vector<int> u1, u2;
      rep(j, v.size()) {
        if (j % 2 == 0) u1.push_back(v[j]);
        else u2.push_back(v[j]);
      }
      rep(j, u1.size()) {
        rep(k, u2.size()) {
          a[u1[j]][u2[k]] = level;
          a[u2[k]][u1[j]] = level;
        }
      }
      nxt.push_back(u1);
      nxt.push_back(u2);
    }
    res = nxt;
    level++;
  }
  rep(i, n) {
    FOR(j, i + 1, n) {
      cout << a[i][j] << (j == n - 1 ? '\n' : ' ');
    }
  }




  

  
  return 0;
}