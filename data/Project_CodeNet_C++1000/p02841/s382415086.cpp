#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int m1, d1, m2, d2;
  cin >> m1 >> d1 >> m2 >> d2;
  int result = (m1 != m2) ? 1 : 0;
  cout << result << endl;
  return 0;
}
