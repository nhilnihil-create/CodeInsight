#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;
//cout << fixed << setprecision(15) << y << endl;
//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int A, B, M;
  double H;
  cin >> A >> B >> H >> M;
  H += M / 60.0;
  double ag_h = H / 12.0;
  double ag_m = M / 60.0;
  double angle = degreeToRadian(abs(ag_h - ag_m)) * 360;
  double ans = A*A + B*B - 2*A*B*cos(angle);
  cout << fixed << setprecision(15) << sqrt(ans) << endl;
  return 0;
}
