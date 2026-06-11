#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> vec(n);
  for (int i = 1; i <= n; ++i)
    vec[i - 1] = l + i - 1;

  sort(vec.begin(), vec.end(),
       [](auto const &lhs, auto const &rhs) { return abs(lhs) < abs(rhs); });

  int ans = accumulate(vec.begin() + 1, vec.end(), 0);
  cout << ans << endl;
}