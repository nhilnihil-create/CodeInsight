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
  int k;
  cin >> k;
  vector<int> a(k+100);
  a.at(0) = 0;
  a.at(1) = 7 % k;
  bool flag = true;
  for (int i = 2; i < k+1; i++) {
    a.at(i) = (a.at(i-1)*10 + 7)%k;
  }
  for (int i = 1; i < k+1; i++) {
    if (a.at(i) == 0) {
      cout << i << endl;
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << -1 << endl;
  }
}
 