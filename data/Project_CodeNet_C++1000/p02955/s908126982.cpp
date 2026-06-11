#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  ll total = 0;
  for (int a : A) total += a;
  vector<int> xs;
  for (int x = 1; x <= sqrt(total); x++) {
    if (total % x == 0) {
      xs.push_back(x);
      xs.push_back(total / x);
    }
  }
  sort(xs.begin(), xs.end(), greater<int>());

  for (int x : xs) {
    if (total % x != 0) continue;
    ll lsum = 0, rsum = 0;
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
      B[i] = A[i] % x;
      rsum += x - A[i] % x;
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
      lsum += B[i];
      rsum -= x - B[i];
      if (max(lsum, rsum) <= K) {
        cout << x << endl;
        return 0;
      }
    }
  }
}