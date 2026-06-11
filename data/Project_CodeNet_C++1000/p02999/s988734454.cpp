/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc130_a.cpp
 * time   : Sat May  2 00:44:27 2020
 * quest  : A - Rounding
 *********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x, a;
  cin >> x >> a;
  cout << (x < a ? 0 : 10) << "\n";
  return 0;
}
