#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double l,k;
  cin >> l;
  k = l/3;
  double ans = k*k*(l-2*k);
  cout << fixed << setprecision(7) << ans << endl;
}