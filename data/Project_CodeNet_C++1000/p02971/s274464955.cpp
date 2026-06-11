#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.rbegin(), b.rend());
  
  for(int i=0; i<n; i++) {
    if(a[i]<b[0]) cout << b[0] << endl;
    else if(a[i]==b[0]) cout << b[1] << endl;
  }
  
  return 0;
}