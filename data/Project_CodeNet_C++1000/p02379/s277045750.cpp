#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<double> x(2), y(2);
  cin >> x.at(0) >> y.at(0);
  cin >> x.at(1) >> y.at(1);
  double distx = x.at(0) - x.at(1);
  double disty = y.at(0) - y.at(1);
  cout << fixed << setprecision(8) << sqrt(distx * distx + disty * disty)
       << endl;
}
