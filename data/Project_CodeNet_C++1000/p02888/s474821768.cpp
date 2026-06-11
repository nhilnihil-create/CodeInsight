#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a, a+n);
  
  int s = 0;
  rep(i,n) rep(j0,n-i-1) {
    int j = j0 + i + 1;
    int t = lower_bound(a+j+1, a+n, a[i]+a[j]) - a-j-1;
    s += t;
  }
  
  cout << s << endl;
  return 0;
}