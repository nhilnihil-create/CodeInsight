#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, a, b;
  cin >> n >> a >> b;
  cout << n / (a + b) * a + min(n % (a + b), a) << '\n';
  return 0;
}