#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[100010];
  long long sum = 1, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
    if (sum > 1000000000000000000 / a[i]) {
      ans = -1;
      break;
    }
    sum *= a[i];
  }
  if (ans != -1) {
    ans = sum;
  }
  printf("%lld\n", ans);
  return 0;
}
