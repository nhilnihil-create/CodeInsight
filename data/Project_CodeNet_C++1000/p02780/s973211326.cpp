#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  int num = 0;
  for(int i=0; i<k; i++) num += a[i];
  int ans = num;
  for(int i=k; i<n; i++) {
    num += a[i];
    num -= a[i-k];
    ans = max(num, ans);
  }

  cout << fixed << setprecision(7) << (ans+k)/2.0 << endl;
  return 0;
}