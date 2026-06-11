#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  bool flag=true;
  bool m=false;
  int b=0;
  int c=0;
  for(int i=0; i<n; i++) {
    for(int j=c; j<n; j++) {
      if(a[j]==i+1) {
       // cout << a[j] << endl;
        b++;
        m=true;
        break;
      }
      if(j-1==n) {
        flag=false;
        break;
      }
      c++;
    }
    if(flag==false) break;
  }
  if(m==false) {
    cout << -1 << endl;
    return 0;
  }
  cout << n-b << endl;
  return 0;
}