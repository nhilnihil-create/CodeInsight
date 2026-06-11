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
  string s, t;
  cin >> s >> t;
  int min = 10000;
  for (int i = 0; i < s.size()-t.size()+1; i++) {
    string str = s.substr(i, t.size()); //文字列Sのl文字目からl+r-1文字までの部分文字列を返す
    int count = 0;
    //cout << str << endl;
    rep(j, t.size()) {
      if (str.at(j) != t.at(j)) {
        count++;
      }
    }
    if (min > count) {
      min = count;
    }
  }
  cout << min << endl;
}
