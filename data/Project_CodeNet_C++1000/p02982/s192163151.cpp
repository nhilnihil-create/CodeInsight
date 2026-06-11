#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, D;
  cin >> N >> D;
  vector<vector<ll>> x(N);
  ll a;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> a;
      x[i].push_back(a);
    }
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      long double sum = 0;
      for (int k = 0; k < D; k++) {
        sum += pow(x[i][k] - x[j][k], 2);
      }
      long double result = sqrtl(sum);
      if (floorl(result) == result) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}