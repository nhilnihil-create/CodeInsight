#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  auto p = find(a.begin(), a.end(), 1);
  
  if(p==a.end()) cout << -1 << endl;
  else {
    int num = 0, ans = 0;
    for(int i=0; i<n; i++) {
      if(a[i]!=num+1) ans++;
      else num++;
    }
    cout << ans << endl;
  }
  
  return 0;
}