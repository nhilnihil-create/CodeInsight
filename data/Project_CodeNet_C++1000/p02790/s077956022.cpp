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
  if (a < b) {
    rep(i,b) cout << a;
  }
  else {
    rep(i,a) cout << b;
  }
  cout << endl;
  return 0;
}