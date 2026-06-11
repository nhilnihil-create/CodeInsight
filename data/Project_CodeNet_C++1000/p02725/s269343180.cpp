#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int k, n;
  cin >>k >>n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  int m = a[0] + k - a[n-1];
  for (int i = 1; i < n; i++) {
    m = max(a[i]-a[i-1], m);
  }
   
  int ans = k - m;
  cout << ans << endl;
}