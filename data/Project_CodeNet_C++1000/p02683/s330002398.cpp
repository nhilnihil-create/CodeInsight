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
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, n) {
    int numc;
    cin >> numc;
    c.at(i) = numc;
    rep(j, m) {
      int numa;
      cin >> numa;
      a.at(i).at(j) = numa;
    }
  }
  bool flag = true;
  vector<int> skill(m);
  int min = 100000000;
  for (int tmp = 0; tmp < (1 << 12); tmp++) {
    bitset<12> s(tmp);
    //cout << s << endl;
    int money = 0;
    rep(i, m) {
      skill.at(i) = 0;
    }
    rep(i,n) {
      if (s.test(i)) {
        money += c.at(i);
        rep(j, m) {
          skill.at(j) += a.at(i).at(j);
        }
      }
    }
    bool flag2 = true;
    rep(i, m) {
      if (skill.at(i) < x) {
        flag2 = false;
      }
    }
    if (flag2) {
      flag = false;
      if (min > money) {
        min = money;
      }
    }
  }
  if (flag) {
    cout << -1 << endl;
  }
  else {
    cout << min << endl;
  }
}
