#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, X, L, M{-1000000001}, ans{};
  cin >> N;
  vector<pair<int, int>> v(N);
  for (int i = 0; i != N; ++i) {
    cin >> X >> L;
    v[i] = {X + L, X - L};
  }

  sort(begin(v), end(v));

  for (const auto &p : v)
    if (M <= p.second) ++ans, M = p.first;

  cout << ans << endl;
}
