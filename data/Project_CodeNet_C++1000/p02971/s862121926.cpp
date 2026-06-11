#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int x;
  vector<int> a(n);
  vector<int> b(n);
  for(int i=0; i<n; i++) {
    cin >> x;
    a[i] = x;
    b[i] = x;
  }
  sort(b.rbegin(), b.rend());
  
  for(int i=0; i<n; i++) {
    if(a[i]<b[0]) cout << b[0] << endl;
    else if(a[i]==b[0] && b[0]==b[1]) cout << b[0] << endl;
    else cout << b[1] << endl;
  }
  
  return 0;
}