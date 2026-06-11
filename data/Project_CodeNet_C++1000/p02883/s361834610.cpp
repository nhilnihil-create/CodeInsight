#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

bool isOK(ll x, ll K, vector<ll> &A, vector<ll> &F) {
  ll s = 0;
  for (int i = 0; i < A.size(); i++) {
    s += max(0ll, A[i] - x / F[i]);
  }
  return (s <= K);
}

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N), F(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> F[i];
  }
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());
  ll l = -1, r = 1e12;
  while (l + 1 < r) {
    ll center = (l + r) / 2;
    if (isOK(center, K, A, F)) {
      r = center;
    } else {
      l = center;
    }
  }
  cout << r << endl;
  return 0;
}