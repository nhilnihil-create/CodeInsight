#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int n2 = n / 2;
  if (n % 2 == 1) {
    cout << b[n2] - a[n2] + 1 << endl;
  } else {
    cout << b[n2] + b[n2 - 1] - a[n2] - a[n2 - 1] + 1 << endl;
  }
  return 0;
}