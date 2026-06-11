#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
//#define cocount cout << count << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define Cinint(n) int n;\
cin >> n;
#define Cinvecint(a, n) vector<int> a(n);\
for (int i = 0; i < (int)(n); i++) {\
  int num;\
  cin >> num;\
  a.at(i) = num;\
}
#define Cinstring(s) string s;\
cin >>s;

  

int main() {
  string n;
  cin >> n;
  int sum = 0;
  rep(i, n.size()) {
    sum += n.at(i) - '0';
  }
  if (sum%9 == 0) {
    coYes;
  }
  else {
    coNo;
  }
  //cout << sum << endl;
  //cout << 0 % 9 << endl;
}
 