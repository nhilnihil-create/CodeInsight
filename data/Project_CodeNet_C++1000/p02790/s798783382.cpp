#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;

  rep(i, max(a, b)) cout << min(a, b);
  return 0;
}