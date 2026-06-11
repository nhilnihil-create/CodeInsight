#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  int N;
  cin >> N;
  ll mod = 1e9 + 7;
  ll num[66];
  for (int i = 0; i < 66; i ++) num[i] = 0;
  for (int i = 0; i < N; i ++) {
    ll A;
    cin >> A;
    for (int j = 0; j < 60; j ++) {
      num[j] += A % 2;
      A /= 2;
    }
  }
  ll ans = 0;
  ll bi = 1;
  for (int i = 0; i < 60; i ++) {
    ll kj = num[i] * (N - num[i]);
    kj %= mod;
    kj *= bi;
    kj %= mod;
    ans += kj;
    ans %= mod;
    bi *= 2;
    bi %= mod;
  }
  cout << ans << endl;
}