#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

const int MAX_VALUE = 1'000'000'000;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  int rest = s % MAX_VALUE + 1;
  for (int i = 0; i < k; i++) {
    cout << s << endl;
  }
  for (int i = k; i < n; i++) {
    cout << rest << endl;
  }
  return 0;
}
