#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

bool Doable(ll N, ll K, const vector<ll> &A, const vector<ll> &F, ll x) {
  ll cnt = 0;
  for (int i = 0; i < N; ++i) {
    ll a = A[i];
    ll f = F[i];
    // while (a * f > x) {
    //   --a;
    //   ++cnt;
    // }
    ll na = min(a, x / f);
    cnt += a - na;
  }
  if (cnt <= K) return true;
  else return false;
}

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> F(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> F[i];
  }
  
  sort(A.begin(), A.end());
  sort(F.begin(), F.end());
  reverse(F.begin(), F.end());

  ll p = -1;  // NG
  ll q = ll(1e13); // OK
  while (p + 1 < q) {
    ll mid = (p + q) / 2;
    if (Doable(N, K, A, F, mid)) {
      q = mid;
    } else {
      p = mid;
    }
  }
  cout << q << endl;
  
  return 0;
}
