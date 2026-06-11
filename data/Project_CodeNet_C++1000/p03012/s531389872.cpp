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
  ll N;
  cin >> N;
  vector<ll> W(N), accum(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
    if (i == 0)
      accum[0] = W[0];
    else
      accum[i] = accum[i - 1] + W[i];
  }
  ll ans = INF;
  for (int i = 0; i < N; i++) {
    ans = min(ans, abs(accum[i] - (accum[N - 1] - accum[i])));
  }
  cout << ans << endl;
  return 0;
}