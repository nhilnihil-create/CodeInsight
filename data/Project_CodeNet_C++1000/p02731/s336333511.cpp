#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  long double L,ans;
  cin >> L;
  ans = pow(L/3,3);
  cout << fixed;
  cout << setprecision(12) <<ans << endl;
  //cout << ans << endl;
  return 0;
}