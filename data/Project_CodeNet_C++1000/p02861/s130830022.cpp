#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  rep(i,N) cin >> x[i] >> y[i];
  double dis = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i+1; j < N; ++j) {
      dis += sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
    }
  }
  int way = 1;
  rep(i,N) way *= i+1;
  double ans = dis * 2 / N;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}