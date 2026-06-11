#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  double L;
  cin >> L;
  cout << fixed << setprecision(12) << pow(L/3.0, 3) << endl;
  return 0;
}