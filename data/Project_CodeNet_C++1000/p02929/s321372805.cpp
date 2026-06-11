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
const int MOD = 1000000007;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  string s; cin >> s;
  n *= 2;
  vector<bool> vl(n);

  vl[0] = true;
  for(int i=1;i<n;++i) {
    if(s[i] == s[i-1]) vl[i] = !vl[i-1];
    else vl[i] = vl[i-1];
  }

  if(s[0] == 'W' || s[n-1] == 'W') {
    cout << 0 << endl;
    return 0;
  }

  ll cnt = 1;
  ll cntl = 1, cntr = 0;
  for(int i=1;i<n;++i) {
    if(vl[i]) {
      cntl++;
    } else {
      cnt *= cntl - cntr;
      cnt %= MOD;
      cntr++;
    }
  }
  if(cntl != cntr) {
    cout << 0 << endl;
    return 0;
  }

  for(int i=1;i<=n/2;++i) {
    cnt *= i;
    cnt %= MOD;
  }
  cout << cnt << endl;

}
