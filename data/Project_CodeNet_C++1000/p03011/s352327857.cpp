#include <bits/stdc++.h>
using namespace std;
int main() {
  int AB, BC, CA;
  cin >> AB >> BC >> CA;
  vector<int> ABC(3);
  ABC.at(0) = AB + BC;
  ABC.at(1) = AB + CA;
  ABC.at(2) = BC + CA;
  sort(ABC.begin(), ABC.end());
  cout << ABC.at(0) << endl;
}