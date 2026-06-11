#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N;
vector<vector<pair<int, int>>> x;

int main() {
  cin >> N;
  x.resize(N);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    x[i].resize(A);
    for (int j = 0; j < A; j++) {
      int x1, x2;
      cin >> x1 >> x2;
      x[i][j] = make_pair(x1, x2);
    }
  }

  int res = 0;
  for (int i = 1; i < (1 << N); i++) {
    bool consistent = true;

    for (int j = 0; j < N; j++) {
      bool is_honest = (i & (1 << j)) > 0;
      if (!is_honest) {
        continue;
      }

      for (auto p : x[j]) {
        int target = p.first - 1;
        bool target_is_honest = (i & (1 << target)) > 0;
        if ((target_is_honest ? 1 : 0) != p.second) {
          consistent = false;
        }
      }
    }

    if (consistent) {
      int tmp = bitset<32>(i).count();
      if (tmp > res)
        res = tmp;
    }
  }
  cout << res << endl;

  return 0;
}
