#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

double a, b, x;

int main() {
  cin >> a >> b >> x;
  if(a * a * b >= 2 * x) {
    double ans;
    ans = 360 * atan(a * b * b / (2 * x)) / (M_PI * 2);
    cout << std::fixed << std::setprecision(8) << ans << endl;
    return 0;
  }
  double ans;
  ans = 360 * atan(2 * (a * a * b - x) / (a * a * a)) / (M_PI * 2);
  cout << std::fixed << std::setprecision(8) << ans << endl;
  return 0;
}