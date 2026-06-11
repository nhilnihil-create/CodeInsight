#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  int a;
  rep(i, m) {
    cin >> a;
    sum += a;
  }
  if (n - sum < 0) {
    cout << -1 << endl;
  } else {
    cout << n - sum << endl;
  }
  return 0;
}
