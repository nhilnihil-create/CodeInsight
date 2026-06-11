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
  int n, m;
  cin >> n >> m;
  vector<int> h(n+1);
  for (int i= 1; i< n+1; i++) {
    int num;
    cin >> num;
    h.at(i) = num;
  }
  h.at(0) = -100;
  vector<int> a(m);
  vector<int> b(m);
  rep(i, m) {
    int aa, bb;
    cin >> aa >> bb;
    a.at(i) = aa;
    b.at(i) = bb;
  }
  vector<bool> check(n+1, true);
  check.at(0) = false;
  rep(i, m) {
    if (h.at(a.at(i)) == h.at(b.at(i))) {
      check.at(a.at(i)) = false;
      check.at(b.at(i)) = false;
    }
    else {
      int numa = h.at(a.at(i));
      int numb = h.at(b.at(i));
      int mini = min(h.at(a.at(i)), h.at(b.at(i)));
      if (mini == numa) {
        check.at(a.at(i)) = false;
      }
      else if (mini == numb) {
        check.at(b.at(i)) = false;
      }
    }
  }
  int count = 0;
  rep(i, n+1) {
    //cout << i << check.at(i) << endl;
    if (check.at(i)) {
      count++;
    }
  }
  cout << count << endl;
}