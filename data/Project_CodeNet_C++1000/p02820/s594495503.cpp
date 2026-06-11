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
  ll N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  string taken = "";
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (T[i] == 'r') {
      if (i >= K && taken[i - K] == 'p') {
        if (i + K < N)
          taken += T[i + K];
        else
          taken += "r";
      } else {
        taken += "p";
        ans += P;
      }
    } else if (T[i] == 's') {
      if (i >= K && taken[i - K] == 'r') {
        if (i + K < N)
          taken += T[i + K];
        else
          taken += "s";
      } else {
        taken += "r";
        ans += R;
      }
    } else {
      if (i >= K && taken[i - K] == 's') {
        if (i + K < N)
          taken += T[i + K];
        else
          taken += "p";
      } else {
        taken += "s";
        ans += S;
      }
    }
  }
  cout << ans << endl;
}