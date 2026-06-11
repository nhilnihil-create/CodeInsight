#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  double a, b, x; cin >> a >> b >> x;
  const double pi = 3.14159265358979323846;
  
  if(a*b*a/2 > x) {
    double aa = 2*x/b/a;
    cout << fixed << setprecision(10) << atan(b/aa)/pi*180 << endl;
  } else {
    double bb = (a*a*b-x)*2/a/a;
    cout << fixed << setprecision(10) << atan(bb/a)/pi*180 << endl;
  }

}