#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long n, k;
  cin >> n >> k;
  vector<bool> hasSweet(n);
  for (long i = 0; i < k; i++) {
    long d;
    cin >> d;
    for (long j = 0; j < d; j++) {
      long a;
      cin >> a;
      hasSweet[a - 1] = true;
    }
  }
  long total = 0;
  for (long i = 0; i < n; i++) {
    if (hasSweet[i]) {
      total++;
    }
  }
  cout << n - total << endl;
  return 0;
}
