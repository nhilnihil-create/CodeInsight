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
  vector<ll> A(N);
  ll comb = 1;
  vector<ll> cnt(3, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    ll t = 0, color = -1;
    if (A[i] == cnt[0]) {
      t++, color = 0;
    }
    if (A[i] == cnt[1]) {
      t++, color = 1;
    }
    if (A[i] == cnt[2]) {
      t++, color = 2;
    }
    if (color == -1) {
      cout << 0 << endl;
      return 0;
    }
    comb = (comb * t) % MOD;
    cnt[color]++;
  }
  cout << comb << endl;
  return 0;
}