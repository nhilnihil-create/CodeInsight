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
  double n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) {
    int num;
    cin >> num;
    a.at(i) = num;
  }
  double sum = 0;
  rep(i, n) {
    sum += a.at(i);
  }
  double border = sum / (4*m);
  int count = 0;
  rep(i, n) {
    if (a.at(i) >= border) {
      count++;
    }
  }
  if (count >= m) {
    coYes;
  }
  else {
    coNo;
  }
}
