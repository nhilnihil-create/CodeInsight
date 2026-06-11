#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  long a[n+1];
  vector<long> ans(n+1);
  for (long i = 2; i <= n; i++) {
    cin >> a[i];
    ans[a[i]] += 1;
  }
  
  for (long i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  
  return 0;
}