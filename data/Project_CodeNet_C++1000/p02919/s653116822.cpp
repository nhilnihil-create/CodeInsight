#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N + 1);
  vector<int> indices(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> P[i];
    indices[P[i]] = i;
  }
  set<int> s;
  s.insert(0);
  s.insert(N + 1);
  long long ans = 0;
  for (int p = N; p >= 1; p--) {
    int i = indices[p];
    auto lb = s.lower_bound(i);
    long long r1 = *lb;
    lb++;
    long long r2;
    if (lb == s.end()) {
      r2 = r1;
    } else {
      r2 = *lb;
    }
    lb--;
    lb--;
    long long l1 = *lb;
    long long l2;
    if (lb == s.begin()) {
      l2 = l1;
    } else {
      lb--;
      l2 = *lb;
    }
    ans += ((r2 - r1) * (i - l1) + (l1 - l2) * (r1 - i)) * p;
    s.insert(i);
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
