#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(void) {
  ll H, N;
  cin >> H >> N;
  vector<ll> minMag(H * 2, INT_MAX);
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  ll ans = INT_MAX;
  minMag[0] = 0;
  for (ll h = 0; h < H; h++) {
    for (ll spell = 0; spell < N; spell++) {
      if (h + A[spell] >= H) {
        ans = min(ans, minMag[h] + B[spell]);
      } else {
        minMag[h + A[spell]] = min(minMag[h + A[spell]], minMag[h] + B[spell]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}