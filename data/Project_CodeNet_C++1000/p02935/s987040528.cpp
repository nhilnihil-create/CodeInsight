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
  vector<int> v(N);
  rep(i,N) cin >> v[i];
  sort(v.begin(), v.end());
  double cur = v[0];
  for (int i = 1; i < N; ++i) {
    cur += v[i];
    cur /= 2.0;
  }
  cout << fixed << setprecision(10) << cur << endl;
  return 0;
}