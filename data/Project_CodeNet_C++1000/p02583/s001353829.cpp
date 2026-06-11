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
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) {
    int x;
    cin >> x;
    l.at(i) = x;
  }
  int count = 0;
  rep(i, n) {
    for (int j=i+1; j < n; j++) {
      for (int k=j+1; k < n; k++) {
        if (l.at(i) != l.at(j)) {
          if (l.at(j) != l.at(k)) {
            if (l.at(k) != l.at(i)) {
              if (l.at(i)+l.at(j) > l.at(k)) {
                if (l.at(j)+l.at(k) > l.at(i)) {
                  if (l.at(k)+l.at(i) > l.at(j)) {
                    count++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << count << endl;
}
