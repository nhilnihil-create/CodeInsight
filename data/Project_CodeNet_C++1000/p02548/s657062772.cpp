#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int a = 1; a <= n; a++) {
    ans += (n - 1) / a;
  }
  cout << ans << endl;
}