#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, x[101], y[101], xy[101], mh = 0, euc = 0, chb = 0, mks = 0;
  long double result1 = 0, result2 = 0, result3 = 0, result4 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
    xy[i] = fabs(x[i] - y[i]);
    mh += xy[i];
    euc += pow(xy[i], 2);
    chb = max(chb, xy[i]);
    mks += pow(xy[i], 3);
  }
  result1 = mh;
  result2 = sqrt(euc);
  result3 = pow(mks, 1.0 / 3.0);
  result4 = chb;
  cout << fixed << setprecision(8);
  cout << result1 << endl;
  cout << result2 << endl;
  cout << result3 << endl;
  cout << result4 << endl;

}
