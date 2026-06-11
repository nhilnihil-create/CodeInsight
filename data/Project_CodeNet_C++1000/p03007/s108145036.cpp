#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  sort(a, a + n);
  int m = a[n-1];
  for (int i=1; i<n-1; i++) {
    if (a[i] >= 0) {
      m += a[i];
    } else {
      m -= a[i];
    }
  }
  m -= a[0];
  cout<<m<<endl;
  int left = a[0];
  int right = a[n-1];
  for (int i=1; i<n-1; i++) {
    if (a[i] >= 0) {
      cout<<left<<" "<<a[i]<<endl;
      left -= a[i];
    } else {
      cout<<right<<" "<<a[i]<<endl;
      right -= a[i];
    }
  }
  cout<<right<<" "<<left<<endl;
}