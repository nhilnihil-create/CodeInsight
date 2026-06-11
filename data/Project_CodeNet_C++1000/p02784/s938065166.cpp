#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, n, a, total = 0;
  cin >> h >> n;
  rep(i, n) {
    cin >> a;
    total += a;
  }
  cout << (h <= total ? "Yes" : "No") << endl;
  return 0;
}
