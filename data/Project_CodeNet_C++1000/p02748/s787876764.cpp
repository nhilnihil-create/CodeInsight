#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
const int INF = 100100100;

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  vector<ll> A(a), B(b);
  rep(i, a) cin >> A[i];
  rep(i, b) cin >> B[i];
  vector<int> x(m), y(m), c(m);
  rep(i, m) cin >> x[i] >> y[i] >> c[i];
  ll mn = INF;
  //つかうなら
  rep(i, m) { mn = min(mn, A[x[i] - 1] + B[y[i] - 1] - c[i]); }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());  //ソート

  rep(i, min(a, b)) { mn = min(mn, A[i] + B[i]); }  //つかわないなら

  cout << mn;
  return 0;
}
