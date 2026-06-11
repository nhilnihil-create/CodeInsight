#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
  ll N, x, m{}, ans{1};
  cin >> N;
  vector<int> D(N);
  for (int i = 0; i != N; ++i) {
    cin >> x;
    if ((!i && x) || (i && !x)) {
      cout << 0 << endl;
      return 0;
    }
    m = max(m,x);
    ++D[x];
  }

  for (int i = 1; i <= m; ++i) {
    if (!D[i]) {
      ans = 0;
      break;
    }
    for (int j = 0; j != D[i]; ++j) {
      ans = ans * D[i-1] % MOD;
    }
  }
  cout << ans << endl;
}
