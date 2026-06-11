/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc139_a.cpp
 * time   : Sat May  2 01:47:47 2020
 * quest  : A - Tenki
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
  string s, t;
  cin >> s >> t;
  cout << (s[0] == t[0] ? 1 : 0) + (s[1] == t[1] ? 1 : 0) + (s[2] == t[2] ? 1 : 0) << "\n";
  return 0;
}
