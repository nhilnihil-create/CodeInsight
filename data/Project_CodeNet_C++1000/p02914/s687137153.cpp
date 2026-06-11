#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;
vector<ll> A;
ll XorAll;
ll Bonus;

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    A.push_back(a);
    XorAll ^= a;
  }
  for (ll i = 0; i < N; ++i) {
    A[i] &= ~XorAll;
  }
  A.push_back(0);
  ++N;
  ll cnt = 0;
  ll bit = 1ll << 60;
  while (true) {
    sort(A.begin() + cnt, A.end(), greater<ll>());
    if (A[cnt] == 0) break;
    while ((bit & A[cnt]) == 0) bit /= 2;
    for (ll i = cnt + 1; i < N; ++i) {
      if (bit & A[i]) A[i] ^= A[cnt];
    }
    ++cnt;
  }
  ll Bonus = 0;
  for (ll i = 0; i < cnt; ++i) {
    if ((Bonus ^ A[i]) > Bonus) Bonus ^= A[i];
  }
  cout << Bonus * 2 + XorAll << endl;
}
