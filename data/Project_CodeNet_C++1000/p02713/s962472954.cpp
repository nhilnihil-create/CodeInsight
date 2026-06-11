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

  

int main() {
  Cinint(k);
  //cout << k << endl;
  //cout << __gcd(1,__gcd(1, 1)) << endl;
  int count = 0;
  rep1(i, k+1) {
    rep1(j, k+1) {
      rep1(l, k+1) {
        //cout << i << j << l << endl;
        int num = __gcd(i, __gcd(j, l));
        count += num;
        //cout << num << endl; 
      }
    }
  }
  cout << count << endl;
}
