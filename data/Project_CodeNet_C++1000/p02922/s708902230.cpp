#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  if (b == 1) {
    cout << 0 << endl;
    return 0;
  }
  int hole = a;
  int tap = 1;
  while (hole < b) {
    hole += a-1;
    ++tap;
  }
  cout << tap << endl;
  return 0;
}