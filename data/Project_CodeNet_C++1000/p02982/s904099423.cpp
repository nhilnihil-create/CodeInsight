#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int n,d;
  cin >> n >> d;
  vector<vector<int>> v(n, vector<int>(d));
  rep(i,n) rep(j,d) cin >> v[i][j];

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double distanse = 0.0, total = 0.0;
      for (int k = 0; k < d; k++) {
        total += pow(v[i][k]-v[j][k],2);
      }
      distanse = pow(total,0.5);
      if (distanse == float(distanse)) cnt++;
    }
  }
  cout << cnt << endl;
}
