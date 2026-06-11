#include <bitset>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> profs(N);
  for (int n = 0; n < N; ++n) {
    int A;
    cin >> A;
    vector<pair<int, int>> prof(A);
    for (int a = 0; a < A; ++a) {
      int x, y;
      cin >> x >> y;
      prof[a] = {x-1, y};
    }
    profs[n] = prof;
  }

  int res = 0;
  for (int64_t i = 0, end = pow(2, N); i < end; ++i) {
    bitset<15> bs(i);
    int trustful = 0;
    bool success = true;
    for (size_t n = 0; n < N; ++n) {
      if (bs.test(n)) {
        for (const auto& p : profs[n]) {
          if ((p.second == 0 && bs.test(p.first))
              || (p.second == 1 && !bs.test(p.first))) {
            success = false; break;
          } 
        }
        ++trustful;
      }
      if (!success) break;
    }
    if (success) {
      res = max(res, trustful);
    }
  }
  cout << res << endl;
  
  return 0;
}
