#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
ll A[N], F[N];
ll n, k;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i=1; i<=n; ++i) {
    cin >> A[i];
  }
  for (int i=1; i<=n; ++i) {
    cin >> F[i];
  }
  sort(A+1, A+n+1);
  sort(F+1, F+n+1);
  reverse(F+1, F+n+1);

  ll lo = 0, hi = 1e18;
  while (lo < hi) 
  {
    ll mid = (lo+hi)/2;
    ll sum = 0;
    for (int i=1; i<=n; ++i) {
      if (A[i]*F[i] > mid) {
        sum += A[i] - mid/F[i];
      }
    }

    if (sum > k) {
      lo = mid+1;
    } else {
      hi = mid;
    }
  }
  cout << lo << endl;

  return 0;
}
