#define _GLIBCXX_DEBUG 
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
  bool flag = true;
  string s;
  cin >> s;
  string s_rev;
  s_rev = s;
  int n;
  n = s.size();
  reverse(s_rev.begin(), s_rev.end());
  if (s_rev == s) {
    string s2 = s.substr((n+3)/2-1); //文字列Sのl文字目から最後の文字までの部分文字列を返す(一番初めは0文字目)
    string s1 = s.substr(0, (n-1)/2); //文字列Sのl文字目からl+r-1文字までの部分文字列を返す(同上)
    string s1_rev = s1;
    string s2_rev = s2;
    reverse(s1_rev.begin(), s1_rev.end());
    reverse(s2_rev.begin(), s2_rev.end());
    if (s1_rev == s1) {
      if (s2_rev == s2) {
        coYes;
        flag = false;
      }
    }
  }
  if (flag) {
    coNo;
  }
}
