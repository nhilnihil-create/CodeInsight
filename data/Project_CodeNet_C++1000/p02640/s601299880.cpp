#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x, y;
  cin >> x >> y;
  bool flag = false;
  rep(i, x+1) {
    rep(j, y+1) {
      if (i+j == x) {
        if (2*i+4*j == y) {
          coYes;
          flag = true;
        }
      }
    }
    if (flag) {
      break;
    }
  }
  if (!flag) {
    coNo;
  }
}

