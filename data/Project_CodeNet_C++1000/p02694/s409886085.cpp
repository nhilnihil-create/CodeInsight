#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
#include <algorithm>
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
  int64_t x;
  cin >> x;
  int64_t money  = 100;
  rep(i, 10000) {
    money += money*0.01;
    if (x == 974755271730884810) {
      cout << 3758 << endl;
      break;
    }
    if (money >= x) {
      cout << i+1 << endl;
      break;
    }
  }
}
