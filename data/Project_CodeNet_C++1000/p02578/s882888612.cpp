#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[200010], maxm;
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  maxm = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > maxm) maxm = a[i];
    sum += (maxm - a[i]);
  }
  cout << sum << endl;
  return 0;
}
