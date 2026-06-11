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
ll const MOD = 1e9 + 7;

int main() {
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  for (ll i = K; i <= N + 1; i++) {
    ll least = i * (i - 1) / 2;
    ll most = i * (2 * N - i + 1) / 2;
    ans = (ans + most - least + 1) % MOD;
  }
  cout << ans << endl;
  return 0;
}