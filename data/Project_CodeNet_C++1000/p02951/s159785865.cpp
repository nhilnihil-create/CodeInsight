/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc136_a.cpp
 * time   : Sat May  2 01:39:08 2020
 * quest  : A - Transfer
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
  int a, b, c;
  cin >> a >> b >> c;
  cout << max(0, c - (a - b)) << "\n";
  return 0;
}
