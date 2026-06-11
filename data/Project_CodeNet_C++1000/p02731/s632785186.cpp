#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int L;
  cin >> L;
  double memo = (L + 0.0) / 3;
  double ans = memo * memo * memo;
  cout << fixed << setprecision(16);
  cout << ans << endl;
}
  