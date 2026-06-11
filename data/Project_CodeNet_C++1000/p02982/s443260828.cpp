#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d; cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  int ans = 0;
  rep(i,n) rep(j,d) {
    cin >> x[i][j];
  }

  rep(i,n-1) {
    for (int j = i+1; j<n; j++) {
      int sum = 0;
      rep(k,d) {
        int yz = x[i][k] - x[j][k];
        sum += yz*yz;
      }
      for (int p=1; p*p<=sum; p++) {
        if (p*p == sum) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}