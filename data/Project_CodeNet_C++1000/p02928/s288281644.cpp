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
ll const MOD = 1000000007;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll seq_cnt = 0, inter_cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[i] > A[j]) {
        seq_cnt++;
      }
    }
    for (int j = 0; j < N; j++) {
      if (A[i] > A[j]) {
        inter_cnt++;
      }
    }
  }
  ll ans = K * (K - 1) / 2;
  ans = ((ans % MOD) * inter_cnt) % MOD;
  ans += seq_cnt * K;
  cout << ans % MOD << endl;
  return 0;
}