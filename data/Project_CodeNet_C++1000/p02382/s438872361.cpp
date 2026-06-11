#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main(void) {
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  int x[n], y[n];
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> y[i];
  }

  int ans1 = 0;
  long double ans2 = 0.0;
  long double ans3 = 0.0;
  int ans4 = 0;
  for(int i = 0; i < n; i++) {
    ans1 += abs(x[i] - y[i]);
    ans2 += pow(abs(x[i] - y[i]), 2);
    ans3 += pow(abs(x[i] - y[i]), 3);
    ans4 = max(ans4, abs(x[i] - y[i]));
  }
  cout << ans1 << endl;
  cout << pow(ans2, (double)1 / 2) << endl;
  cout << pow(ans3, (double)1 / 3) << endl;
  cout << ans4 << endl;

  return 0;
}

