#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    if(i % 2 == 0) {
      if(!(s[i] == 'R' | s[i] == 'U' | s[i] == 'D')) {
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      if(!(s[i] == 'L' | s[i] == 'U' | s[i] == 'D')) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  
  cout << "Yes" << endl;  
}