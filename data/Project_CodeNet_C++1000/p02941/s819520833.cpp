#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  set<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    s.insert({b[i], i});
  }

  long long result = 0;
  for (;;) {
    if (s.empty()) break;

    int i = prev(s.end())->second;
    s.erase(prev(s.end()));

    int i1 = (i + 1) % n;
    int i2 = (i + n - 1) % n;

    int sum = b[i1] + b[i2];

    if (b[i] < a[i]) {
      cout << -1 << endl;
      return 0;
    }

    if (b[i] == a[i]) {
      continue;
    }
    if (b[i] <= sum) {
      cout << -1 << endl;
      return 0;
    }
    int t = (b[i] - a[i]) / sum;
    if (t == 0) {
      cout << -1 << endl;
      return 0;
    }
    result += t;
    b[i] -= t * sum;
    s.insert({b[i], i});
  }
  cout << result << endl;

  return 0;
}
