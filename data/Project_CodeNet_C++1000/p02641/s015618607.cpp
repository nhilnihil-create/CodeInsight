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
  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  rep(i, n) {
    int num;
    cin >> num;
    p.at(i) = num;
  }
  sort(p.begin(), p.end());
  vector<int> check(102, 0);
  rep(i, n) {
    check.at(p.at(i)) = 1;
  }
  vector<int> x_chikasa(102);
  for (int i = 0; i < 102; i++) {
    x_chikasa.at(i) = i-x;
  }
  int min = 1000;
  int min_num = 1000;
  for (int i = 0; i<102; i++) {
    if (check.at(i) == 0) {
      if (abs(x_chikasa.at(i)) < min) {
        min = abs(x_chikasa.at(i));
        min_num = i;
      }
    }
  }
  cout << min_num << endl;
}
      
