#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  vector<int> a(n+1);
  for (int i=0; i<n; i++) cin>>a[i+1];
  for (int _=0; _<k; _++) {
    vector<int> tmp(n+2);
    for (int i=1; i<n+1; i++) {
      ++tmp[max(i-a[i], 0)];
      --tmp[min(i+a[i]+1, n+1)];
    }
    a[0] = tmp[0];
    bool all_n = true;
    for (int i=1; i<n+1; i++) {
      a[i] = a[i-1] + tmp[i];
      if (a[i] != n) {
        all_n = false;
      }
    }
    if (all_n) {
      break;
    }
  }
  for (int i=0; i<n; i++) {
    cout<<a[i+1];
    if (i != n - 1) {
      cout<<" ";
    }
  }
  cout<<endl;
}