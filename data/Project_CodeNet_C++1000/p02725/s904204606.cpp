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
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  rep(i, n) {
    int num;
    cin >> num;
    a.at(i) = num;
  }
  vector<int> distance(n);
  for (int i = 0; i < n-1; i++) {
    distance.at(i) = a.at(i+1) - a.at(i);
  }
  distance.at(n-1) = k-a.at(n-1) + a.at(0);
  int max = 0;
  rep(i, n) {
    if (max < distance.at(i)) {
      max = distance.at(i);
    }
  }
  cout << k-max << endl;
}
