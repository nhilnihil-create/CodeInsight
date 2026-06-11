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
  ll N;
  cin >> N;
  ll A;
  vector<ll> zero_cnt(65);
  for (int i = 0; i < N; i++) {
    cin >> A;
    for (int j = 0; j < 60; j++) {
      zero_cnt[j] += A % 2;
      A /= 2;
    }
  }
  ll ans = 0;
  ll base = 1;
  for (int i = 0; i < 60; i++) {
    ll sum = (zero_cnt[i] * (N - zero_cnt[i])) % MOD;
    sum = (sum * base) % MOD;
    ans = (ans + sum) % MOD;
    base = (base * 2) % MOD;
  }
  cout << ans << endl;
  return 0;
}