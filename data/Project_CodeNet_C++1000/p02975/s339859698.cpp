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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  if (n % 3 != 0) cout << (a == vector<int>(n, 0) ? "Yes" : "No") << '\n';
  else {
    sort(a.begin(), a.end());
    if (a == vector<int>(n, 0)) {
      cout << "Yes" << '\n';
      return 0;
    }
    int x = a[n / 3];
    vector<int> res(n / 3, 0);
    rep(i, n * 2 / 3) res.push_back(x);
    if (a == res) {
      cout << "Yes" << '\n';
      return 0;
    }
    int y = a[n * 2 / 3];
    int z = a[0];
    int xsum = x ^ y ^ z;
    if (xsum != 0) {
      cout << "No" << '\n';
      return 0;
    }
    res.clear();
    rep(i, n / 3) res.push_back(z);
    rep(i, n / 3) res.push_back(x);
    rep(i, n / 3) res.push_back(y);
    if (a == res) {
      cout << "Yes" << '\n';
    }
    else cout << "No" << '\n';
  }





  
  return 0;
}