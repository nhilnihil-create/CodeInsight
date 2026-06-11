#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long n, k;
  cin >> n >> k;

  long long result;
  if (n <= k) {
    result = min(n, k - n);
  } else {
    // result = n % min(k, n - k);
    result = n % min(k, n - k);
    if (result < k) result = min(result, k - result);
  }

  cout << result << endl;
  return 0;
}