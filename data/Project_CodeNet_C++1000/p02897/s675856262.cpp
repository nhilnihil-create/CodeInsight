#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int n;
  cin >> n;

  double ans = ceil(n / 2.0) / double(n);
  cout << fixed << setprecision(10) << ans << endl;
}
