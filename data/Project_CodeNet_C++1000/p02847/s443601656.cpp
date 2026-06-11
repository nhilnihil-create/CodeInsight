#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<string,int> list;
  list["SUN"] = 7;
  list["MON"] = 6;
  list["TUE"] = 5;
  list["WED"] = 4;
  list["THU"] = 3;
  list["FRI"] = 2;
  list["SAT"] = 1;
  cout << list.at(s) << endl;
}