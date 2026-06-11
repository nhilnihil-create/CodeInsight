#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  int a[100000], p = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > 0) ++p;
  }
  
  sort(a, a+n);
  
  if (p == 0) ++p;
  if (p == n) --p;
  
  int m = 0;
  for (int i = 0; i < n-p; ++i) m -= a[i];
  for (int i = n-p; i < n; ++i) m += a[i];
  
  cout << m << endl;
  
  int sm1 = a[n-1];
  for (int i = 1; i < n-p; ++i) {
    cout << sm1 << " " << a[i] << endl;
    sm1 -= a[i];
  }
  
  int sm2 = a[0];
  for (int i = n-p; i < n-1; ++i) {
    cout << sm2 << " " << a[i] << endl;
    sm2 -= a[i];
  }
  
  cout << sm1 << " " << sm2 << endl;
  return 0;
}