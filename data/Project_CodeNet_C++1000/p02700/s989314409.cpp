#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  while(a>0 & c>0) {
    c -= b;
    a -= d;
  }
  if(a > 0)
    cout << "Yes" << endl;
  else {
    if(c <= 0)
      cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}