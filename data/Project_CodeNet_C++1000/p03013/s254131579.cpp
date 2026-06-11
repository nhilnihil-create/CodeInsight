#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int64_t mod = 1000000007;

int main() {
  int64_t n, m;
  cin >> n >> m;

  vector<bool> broken(n + 1);
  rep(i, m) { 
    int a;
    cin >> a;
    broken.at(a) = true;
  }

  vector<int64_t> dp(n + 2);
  dp.at(n) = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (broken.at(i)) {
      dp.at(i) = 0;
      continue;
    } else {
      dp.at(i) = (dp.at(i + 1) + dp.at(i + 2)) % mod;
    }
  }

  cout << dp.at(0) << endl;
  return 0;
}