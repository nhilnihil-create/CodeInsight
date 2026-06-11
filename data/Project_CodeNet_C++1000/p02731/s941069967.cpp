#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int l;
  cin >> l;
  double ans = (double)l / 3.0;
  ans = pow(ans, 3.0);
  
  printf("%.10f\n", ans);
  return 0;
}