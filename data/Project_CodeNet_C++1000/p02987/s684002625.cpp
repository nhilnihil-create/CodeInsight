#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  if(s[0] == s[1] & s[2] == s[3] & s[0] != s[2])
    cout << "Yes" << endl;
  else if(s[0] == s[2] & s[1] == s[3] & s[0] != s[1])
    cout << "Yes" << endl;
  else if(s[0] == s[3] & s[1] == s[2] & s[0] != s[1])
    cout << "Yes" << endl;
  else cout << "No" << endl;
  
}