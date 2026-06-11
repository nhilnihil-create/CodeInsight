#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,P;
  string S;
  cin >> N >> P >> S;
  if (P == 2) {
    ll res = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] == '2' || S[i] == '4' || S[i] == '6' || S[i] == '8' || S[i] == '0') {
        res += i+1;
      }
    }
    cout << res << endl;
    return 0;
  }
  if (P == 5) {
    ll res = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] == '5' || S[i] == '0') {
        res += i+1;
      }
    }
    cout << res << endl;
    return 0;
  }
  ll modP[P];
  for (int i = 0; i < P; i++) modP[i] =0;
  ll R[N+1];
  ll power10[300000];
  power10[0] = 1;
  for (int i = 1; i < 300000; i++) {
    power10[i] = power10[i-1] * 10;
    power10[i] %= P;
  }
  R[0] = 0;
  modP[0]++;
  for (int i = 0; i < N; i++) {
    int num = S[N-i-1] - '0';
    R[i+1] = (R[i] + (power10[i] * num)) % P;
    modP[R[i+1]]++;
  }
  ll ans = 0;
  for (int i = 0; i < P; i++) {
    if (modP[i] > 0) {
      ans += (modP[i] * (modP[i] - 1)) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
