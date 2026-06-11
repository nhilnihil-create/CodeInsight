#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> x[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double p = 0;
      for (int k = 0; k < d; k++) {
        p += pow(x[i][k] - x[j][k], 2);
      }
      p = sqrt(p);
      if (p == floor(p)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}