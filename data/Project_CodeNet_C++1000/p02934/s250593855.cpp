#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  double ans = 0.0, A;
  rep(i,n){
    cin >> A;
    ans += 1.0 / A;
  }
  ans = 1.0 / ans;
  cout << setprecision(16) << ans;
  return 0;
}