#include <iostream>
#include <numeric>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  rep(i,n) cin >> a[i];
  
  int p = 1;
  rep(i,n) p = lcm(p, a[i]);
  rep(i,n) if(p / 2 % a[i] != a[i] / 2) p = 2 * m + 2;
  
  cout << (m - p / 2) / p + (m >= p / 2) << endl;
  return 0;
}