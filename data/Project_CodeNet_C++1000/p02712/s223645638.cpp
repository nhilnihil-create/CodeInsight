#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if ((i%3) && (i%5)) {
      ans += i;
    }
  }
  cout << ans << endl;
}
