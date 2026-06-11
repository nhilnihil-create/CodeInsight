#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  
  int64_t ans = 0;
  for(int i=k; i<n; i++) ans += v[i];
  
  cout << ans << endl;
  return 0;
}