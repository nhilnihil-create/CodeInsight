#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll A[200006];
int N, K;

bool f(ll x) {
  int cnt = 0;
  for (int i= 0; i < N; i++) {
    if (A[i] <= x) continue;
    cnt += (int)ceil(1.0 * A[i] / x) - 1;
  }
  return cnt <= K;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  ll ub = 1LL << 60;
  ll lb = 0;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    if (f(mid)) ub = mid;
    else lb = mid;
  }
  cout << ub << endl;
}