#include <bits/stdc++.h>

using namespace std;

int main() {
  size_t N;
  cin >> N;
  multiset<int, greater<int>> s(greater<int>{});
  auto num = pow(2, N);
  for (size_t i = 0; i < num; ++i) {
    int S;
    cin >> S;
    s.emplace(S);
  }
  vector<int> done;
  done.reserve(num);

  vector<int> adding;
  adding.reserve(num / 2);

  auto it = s.begin();
  adding.emplace_back(*it);
  s.erase(it);

  while (!s.empty()) {
    for (int val : adding) {
      done.emplace_back(val);
    }
    adding.clear();
    sort(done.rbegin(), done.rend());
    for (int val : done) {
      auto it = s.upper_bound(val);
      if (it == s.end()) {
        cout << "No" << endl;
        return 0;
      }
      adding.emplace_back(*it);
      s.erase(it);
    }
  }
  cout << "Yes" << endl;
}
