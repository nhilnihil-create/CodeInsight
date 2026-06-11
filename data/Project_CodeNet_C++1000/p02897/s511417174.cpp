#include <bits/stdc++.h>
using namespace std;

int main() {
  double n;
  cin >> n;
  double p = floor((n + 1) / 2) / n;
  cout << fixed << setprecision(8) << p << endl;
}