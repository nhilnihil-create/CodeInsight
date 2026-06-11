#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> v(N);  // B, A
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(b, a);
  }
  sort(v.begin(), v.end());
  bool ok = true;
  int now = 0;
  for (auto p : v) {
    now += p.second;
    if (now > p.first) {
      ok = false;
      break;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
