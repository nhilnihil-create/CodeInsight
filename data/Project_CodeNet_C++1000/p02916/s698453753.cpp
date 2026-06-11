#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for(int i=0; i<n; i++) {
    cin >> b[i];
  }
  vector<int> c(n);
  for(int i=0; i<n-1; i++) {
    cin >> c[i];
  }
  
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += b[a[i]-1];
    if (i>0 && a[i-1]+1 == a[i]) {
      sum += c[a[i]-2];
    }
  }
  cout << sum << endl;
}