#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

using ll = long long;
typedef pair<ll, ll> P_ll;
typedef pair<int, int> P;

const ll INF_ll = 1e17;
const int INF = 1e8;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> xy(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    cin >> xy[i][0] >> xy[i][1];
  }
  long double ans = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      long double d =
          sqrtl(powl(xy[i][0] - xy[j][0], 2) + powl(xy[i][1] - xy[j][1], 2));
      ans += d;
      // cout << i << " " << j << " " << d << endl;
    }
  }
  cout << setprecision(15) << ans * 2 / N << endl;

  return 0;
}