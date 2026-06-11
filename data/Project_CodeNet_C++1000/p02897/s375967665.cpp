#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  if (N % 2 == 0) {
    cout << 0.5 << endl;
  }
  else {
    double ans = ((N / 2 + 1.0) / N);
    cout << fixed << setprecision(16);
    cout << ans << endl;
  }
}