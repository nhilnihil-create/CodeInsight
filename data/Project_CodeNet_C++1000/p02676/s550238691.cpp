#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;

  if(k >= s.size()) cout << s << endl;
  else {
    s = s.substr(0,k) + "...";
    cout << s << endl;
  }
}