#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, r;
  cin >> n >> r;
  cout << r + 100 * max(10 - n, 0) << endl;
  return 0;
}
