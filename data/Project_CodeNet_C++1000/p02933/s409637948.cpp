/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc138_a.cpp
 * time   : Sat May  2 01:43:51 2020
 * quest  : A - Red or Not
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
  int a; string s;
  cin >> a >> s;
  cout << (a < 3200 ? "red" : s) << "\n";
  return 0;
}
