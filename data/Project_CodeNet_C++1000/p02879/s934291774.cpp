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
  int A, B;
  cin >> A >> B;
  if (A > 9 || B > 9) cout << -1 << endl;
  else cout << A*B << endl;
  return 0;
}