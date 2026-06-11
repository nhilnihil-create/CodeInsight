#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, ans{};
  string S;
  cin >> N >> S;
  vector<vector<int>> v(10);
  for (int i = 0; i != N; ++i)
    v[S[i]-'0'].push_back(i);
  for (int i = 0; i != 10; ++i) {
    if (v[i].empty()) continue;
    for (int k = 0; k != 10; ++k) {
      if (v[k].empty()) continue;
      for (int j = 0; j != 10; ++j) {
        auto it1 = upper_bound(begin(v[j]),end(v[j]),v[i].front());
        auto it2 = lower_bound(begin(v[j]),end(v[j]),v[k].back());
        if (it2 - it1 > 0) ++ans;
      }
    }
  }
  cout << ans << endl;
}
