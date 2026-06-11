#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
using ll = long long;
const int INF = 1e8;

int main() {
  int N;
  cin >> N;
  vector<vector<ll>> L(N, vector<ll>(2));
  for (int i = 0; i < N; i++) {
    ll L_tmp;
    ll X_tmp;
    cin >> X_tmp >> L_tmp;
    L[i][0] = X_tmp - L_tmp;
    L[i][1] = X_tmp + L_tmp;
  }
  sort(L.begin(), L.end(), [](const vector<ll> &alpha, const vector<ll> &beta) {
    return alpha[1] < beta[1];
  });

  int ans = 1;
  ll x_last = L[0][1];
  for (int i = 1; i < N; i++) {
    if (L[i][0] < x_last) {
      continue;
    }
    x_last = L[i][1];
    ans++;
  }

  cout << ans << endl;

  return 0;
}
