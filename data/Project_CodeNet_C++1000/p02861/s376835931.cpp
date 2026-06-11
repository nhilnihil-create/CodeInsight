#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (int)(a);i < (int)(b);i++)

int main() {
  int n;
  cin >> n;
  double s = 0;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  rep(i, 0, n) {
    rep(j, i+1, n) {
      s += sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
  }
  cout << fixed << setprecision(8) << s*2/n << endl;
}