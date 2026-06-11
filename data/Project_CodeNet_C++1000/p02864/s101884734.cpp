#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, k; cin >> n >> k;
  vll h(n+1);
  for(int i=0;i<n;++i) {
    cin >> h[i+1];
  }
  if(n == 1 && k == 0) {
    cout << h[1] << endl;
    return 0;
  }
  if(n == 1 && k == 1) {
    cout << h[0] << endl;
    return 0;
  }


  vvll dp(n+1, vll(n+1, LINF));
  dp[0][0] = 0;
  for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) {
      for(int k=i+1;k<=n;++k) {
        dp[k][j+1] = min(dp[k][j+1], dp[i][j] + max(0ll, h[k] - h[i]));
      }
    }
  }

  ll mi = LINF;
  for(int i=1;i<=n;++i) {
    mi = min(mi, dp[i][n-k]);
  }
  cout << (mi == LINF ? 0 : mi) << endl;

}
