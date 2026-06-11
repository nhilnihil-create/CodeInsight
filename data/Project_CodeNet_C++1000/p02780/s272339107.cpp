#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

double f(double n) {
  return (n+1) / 2;
}

int main() {
  cout << fixed << setprecision(10);
  double n, k; cin >> n >> k;
  vector<double> p(n);
  rep(i,n) cin >> p[i];

  double sum = 0, ans = 0;
  int j = 0, c = 0;
  rep(i,n-k+1) {
    while(c != k) {
      sum += f(p[j]);
      c++; j++;
    }
    ans = max(ans, sum);
    sum -= f(p[i]); c--;
  }
  cout << ans << endl;
  return 0;
}