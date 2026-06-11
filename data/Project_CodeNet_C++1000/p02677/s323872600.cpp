#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int A, B, H, M;
  cin >> A >> B >> H >> M;
  long double radH = 2 * M_PI * (H + M / 60.0) / 12;
  long double radM = 2 * M_PI * M / 60.0;
  long double ans = A * A + B * B - 2 * A * B * cosl(radH - radM);
  ans = sqrtl(ans);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
