#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  for(int i=0; i<n-1; i++) {
    sort(v.rbegin(), v.rend());
    v[n-2-i] = (v[n-2-i]+v[n-1-i])/2;
    v.pop_back();
  }
  
  cout << fixed << setprecision(10) << v[0] << endl;
  return 0;
}