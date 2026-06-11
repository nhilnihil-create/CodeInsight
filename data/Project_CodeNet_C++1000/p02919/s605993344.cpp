#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<int> ms{0, 0, n + 1, n + 1};
  vector<pair<int, int>> a;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.emplace_back(x, i + 1);
  }
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  long long res = 0;
  for (auto& top : a) {
    long long num = top.first;
    int i = top.second;
    auto it = ms.lower_bound(i);
    int r1 = *it++, r2 = *it--;
    it--;
    int l1 = *it--, l2 = *it;
    res += num * (r2 - r1) * (i - l1);
    res += num * (l1 - l2) * (r1 - i);
    ms.insert(i);
  }
  cout << res << '\n';
  return 0;
}