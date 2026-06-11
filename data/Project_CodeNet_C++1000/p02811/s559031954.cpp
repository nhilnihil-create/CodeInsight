#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  cout << (500 * k >= n ? "Yes" : "No");
  return 0;
}
