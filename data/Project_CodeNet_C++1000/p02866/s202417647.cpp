#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A[100001];
int MOD = 998244353;

ll powMod(ll x, ll k) {
  if (k == 0) return 1;
  if (k % 2 == 0)
    return powMod(x * x % MOD, k / 2);
  else
    return x * powMod(x, k - 1) % MOD;
}

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D[i];
    A[D[i]]++;
  }

  if (D[0] != 0 || A[0] != 1) {
    cout << 0 << endl;
    return 0;
  }

  ll ret = 1;
  for (int i = 2; i < N; i++) {
    ret = ret * powMod(A[i - 1], A[i]) % MOD;
  }
  cout << ret << endl;
}