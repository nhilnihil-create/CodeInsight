#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N,M,V,P;
  cin >> N >> M >> V >> P;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  ll left = P - 1;
  ll right = N;
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    ll sum = 0;
    bool can = true;
    if (A[mid] + M < A[P-1]) {
      can = false;
    }
    for (int i = 0; i < N; i++) {
      if (i <= P-2) {
        sum += M;
      } else if (P-1 <= i && i < mid) {
        sum += A[mid] + M - A[i];
      } else {
        sum += M;
      }
    }
    if (sum >= M * V && can) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << right << endl;
  return 0;
}