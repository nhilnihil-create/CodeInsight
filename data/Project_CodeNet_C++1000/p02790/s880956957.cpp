#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  char a, b;
  cin >> a >> b;
  cout << ((a > b) ? string(a - '0', b) : string(b - '0', a));
  return 0;
}
