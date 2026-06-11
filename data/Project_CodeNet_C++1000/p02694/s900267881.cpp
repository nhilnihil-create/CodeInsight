#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  ll crt = 100;
  ll rtn = 0;
  while (1) {
//    crt *= 1.01;
    crt += crt / 100;
    ++rtn;
    if (crt >= x) break;
  }
  cout << rtn << endl;
}
