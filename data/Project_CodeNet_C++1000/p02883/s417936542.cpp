#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;



int main() {
  ll N,K;
  cin >> N >> K;
  ll A[N],F[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> F[i];
  sort(A,A+N);
  sort(F,F+N);
  reverse(F,F+N);
  ll left = -1;
  ll right = 1e13;

  while (right - left > 1) {
    ll mid = (right + left) / 2;
    ll res = 0;
    for (int i = 0; i < N; i++) {
      res += max(A[i] - (mid / F[i]),0LL);
    }
    if (res > K) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << right << endl;
  return 0;
}