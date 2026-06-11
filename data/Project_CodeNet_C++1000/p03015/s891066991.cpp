#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  ll ans = 0;
  ll power2[114514];
  ll power3[114514];
  power2[0] = 1;
  power3[0] = 1;
  for (int i = 1; i < 114514; i++) {
    power2[i] = power2[i-1] * 2;
    power3[i] = power3[i-1] * 3;
    power2[i] %= Mod;
    power3[i] %= Mod;
  }
  int N = S.size();
  vector<ll> one;
  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == '1') {
      one.push_back(i);
    }
  }
  for (int i = 0; i < (int)one.size(); i++) {
    ans += (power2[i] * power3[N - one[i] - 1]) % Mod;
    ans %= Mod;
  }
  ans += power2[(int)one.size()];
  ans %= Mod;
  cout << ans << endl;
  return 0;
}