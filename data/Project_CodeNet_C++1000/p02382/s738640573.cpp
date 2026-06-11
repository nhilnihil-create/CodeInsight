#include <bits/stdc++.h>
using namespace std;

double minkowski(vector<int> &x, vector<int> &y, int p) {
  double ans = 0;
  if (p == 1) {
    for (int i = 0; i < x.size(); i++) {
      ans += fabs(x.at(i) - y.at(i));
    }
    return ans;
  } else if (p == 2) {
    for (int i = 0; i < x.size(); i++) {
      ans += fabs(x.at(i) - y.at(i)) * fabs(x.at(i) - y.at(i));
    }
    ans = sqrt(ans);
  } else if (p == 3) {
    for (int i = 0; i < x.size(); i++) {
      ans += fabs(x.at(i) - y.at(i)) * fabs(x.at(i) - y.at(i)) *
             fabs(x.at(i) - y.at(i));
    }
    ans = cbrt(ans);
  } else if (p == 4) {
    for (int i = 0; i < x.size(); i++) {
      ans = max(ans, fabs(x.at(i) - y.at(i)));
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> y.at(i);
  }
  cout << fixed << setprecision(8) << minkowski(x, y, 1) << endl;
  cout << fixed << setprecision(8) << minkowski(x, y, 2) << endl;
  cout << fixed << setprecision(8) << minkowski(x, y, 3) << endl;
  cout << fixed << setprecision(8) << minkowski(x, y, 4) << endl;
}
