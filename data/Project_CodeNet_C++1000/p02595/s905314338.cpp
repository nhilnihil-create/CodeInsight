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
  int64_t n, d;
  cin >> n >> d;
  vector<int64_t> x(n);
  vector<int64_t> y(n);
  rep(i, n) {
    int64_t xx, yy;
    cin >> xx >> yy;
    x.at(i) = xx;
    y.at(i) = yy;
  }
  int count = 0;
  rep(i, n) {
    if (x.at(i)*x.at(i) + y.at(i)*y.at(i) <= d*d) {
      count++;
    }
  }
  cout << count << endl;
  
}

