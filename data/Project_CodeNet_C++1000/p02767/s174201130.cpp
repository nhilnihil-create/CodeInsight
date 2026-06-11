#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> x(n);
  for(int i=0; i<n; i++) cin >> x[i];
  sort(x.begin(), x.end());
  
  int a = x[0];
  int b = x[n-1];
  int ans = 1000000000;
  for(int i=a; i<=b; i++) {
    int sum = 0;
    for(int j=0; j<n; j++) sum += (i-x[j])*(i-x[j]);
    ans = min(ans, sum);
  }
  
  cout << ans << endl;
  return 0;
}