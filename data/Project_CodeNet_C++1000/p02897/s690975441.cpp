#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double ans;
  int tmp;
  cin >> n;
  if (n%2==0) {
    ans = 0.5;
    cout << ans << endl;
  }
  else {
    tmp = n / 2;
    tmp++;
    ans = (double)tmp / n;
    cout << ans << endl;
  }
  return 0;
}
