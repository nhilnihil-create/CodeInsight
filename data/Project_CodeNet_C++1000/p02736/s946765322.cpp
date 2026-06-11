#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int comb[2][2];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  comb[0][0] = comb[1][0] = comb[1][1] = 1;
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    char c;
    cin >> c;
    a[i] = c-'0';
  }
  vector<int> a2(n-1);
  rep(i, n-1) a2[i] = abs(a[i]-a[i+1]);
  a = a2;
  --n;
  int p = 0;
  rep(i, n) {
    if (a[i]%2 == 0)
      continue;
    int pro = 1;
    rep(j, 30)
      pro *= comb[n-1>>j&1][i>>j&1];
    if (pro) 
      p ^= 1;
  }
  if (p) {
    cout << 1 << endl;
    return 0;
  }
  rep(i, n) {
    if (a[i] == 1) {
      cout << 0 << endl;
      return 0;
    }
  }
  rep(i, n) a[i] /= 2;
  p = 0;
  rep(i, n) {
    if (a[i]%2 == 0)
      continue;
    int pro = 1;
    rep(j, 30)
      pro *= comb[n-1>>j&1][i>>j&1];
    if (pro)
      p ^= 1;
  }
  if (p)
    cout << 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}