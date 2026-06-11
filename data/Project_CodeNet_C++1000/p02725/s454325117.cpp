#include <bits/stdc++.h>
#define FOR(i, c) for (int i = 0; i < c; i++)
#define MOD 1000000007
using namespace std;

int main() {
  int k, n;
  cin >> k >> n;
  int a[n];
  FOR(i, n) {
    cin >> a[i];
  }
  sort(a, a+n);
  int maxx = k-a[n-1]+a[0];
  FOR(i, n) {
    if (i) maxx = max(maxx, a[i]-a[i-1]);
  }
  cout << k-maxx << endl;
  return 0;
}

