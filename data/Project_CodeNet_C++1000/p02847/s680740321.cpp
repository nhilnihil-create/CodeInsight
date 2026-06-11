#include <bits/stdc++.h>
using namespace std;
string ds[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main()
  {string S; cin >> S;
  auto i = find(ds, ds + 7, S) - ds;
  cout << 7 - i << endl;}