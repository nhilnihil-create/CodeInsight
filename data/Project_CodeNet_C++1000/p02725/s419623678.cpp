#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, n;
  cin >> k >> n;
  
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  
  int a=v[0], b=v[n-1];
  int max = v[0]+k-v[n-1];
  for(int i=1; i<n; i++) {
    if(v[i]-v[i-1]>max) {
      max = v[i]-v[i-1];
      a = v[i], b = v[i-1];
    } 
  }
  
  if(a==v[0] && b==v[n-1]) cout << b-a << endl;
  else cout << b+k-a << endl;
  return 0;
}