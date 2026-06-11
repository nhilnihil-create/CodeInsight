#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int L;
  cin >> L;
  double v = pow(L,3);
  double ans;
  ans = double(v/27);
  cout << fixed << setprecision(10);
  cout << ans <<endl;
  return 0;
}