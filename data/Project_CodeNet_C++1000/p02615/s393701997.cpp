#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a, a+n);
  
  int s = a[n-1], p = (n-2)/2, q = n%2;
  rep(i,p) s += 2 * a[n-2-i];
  if(q == 1) s += a[n-2-p];
  cout << s << endl;
  return 0;
}