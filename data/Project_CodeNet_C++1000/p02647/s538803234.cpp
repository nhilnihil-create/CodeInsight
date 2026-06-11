#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];
  vector<int> ans(n, 0);
  
  for (int i=0; i<k; i++) {
    vector<long long> ls(n, 0);
    vector<long long> rs(n, 0);
    
    for (int j=0; j<n; j++) {
      int l = max(j - a[j], 0);
      int r = min(j + a[j], n-1) + 1;
      ls[l]++;
      if (r < n) rs[r]++;
    }
    
    ans[0] = ls[0] - rs[0];
    
    for (int j=1; j<n; j++) {
      ls[j] += ls[j-1];
      rs[j] += rs[j-1];
      ans[j] = ls[j] - rs[j];
    }
      
    for (int j=0; j<n; j++) a[j] = ans[j];
    if (a[0] == n && a[n-1] == n) break;
    
  }
  
  for (int i=0; i<n; i++) cout << ans[i] << " ";

}
