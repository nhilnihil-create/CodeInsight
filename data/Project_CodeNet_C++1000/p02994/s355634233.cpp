#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, l;
  cin >> n >> l;
  int sum = 0;
  if(l <= 0 && 0 <= l+n-1) {
    for(int i=1; i<=n; i++) {
      sum += l+i-1;
    }
    cout << sum << endl;
  }
  
  else if(l > 0) {
    for(int i=1; i<=n; i++) {
      if(i != 1) {
        sum += l+i-1;
      }
    }
    cout << sum << endl;
  }
  else if (l+n-1 < 0) {
    for(int i=1; i<=n; i++) {
      if(i != n) {
        sum += l+i-1;
      }
    }
    cout << sum << endl;
  }
  return 0;
}