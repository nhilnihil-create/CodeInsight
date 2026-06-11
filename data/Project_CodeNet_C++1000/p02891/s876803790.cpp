#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  string S;
  ll K;
  cin >> S >> K;
  vector<int> v;
  int n{};
  char b{};
  for (char c : S) {
    if (b != c && n) {
      v.push_back(n);
      n = 0;
    }
    b = c;
    ++n;
  }
  v.push_back(n);

  ll ans{};
  if (v.size() == 1) {
    ans = K * v[0] / 2;
  } else if (S[0] == S.back()) {
    ans = K * accumulate(begin(v) + 1, end(v) - 1, 0ll,
                         [](ll a, int x) { return a + x / 2; });
    ans += (v[0] + v.back()) / 2 * (K - 1) + v[0] / 2 + v.back() / 2;
  } else {
    ans = K * accumulate(begin(v), end(v), 0ll,
                         [](ll a, int x) { return a + x / 2; });
  }
  cout << ans << endl;
}
