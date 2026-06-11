#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i, n) rep(j, d) cin >> x.at(i).at(j);

  int result = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int sum = 0;
      rep(k, d) {
        sum += pow(x.at(i).at(k) - x.at(j).at(k), 2);
      }
      int sq = ceil(sqrt(sum));
      if (sq * sq == sum) {
        result++;
      }
    }
  }
  cout << result << endl;

  return 0;
}
