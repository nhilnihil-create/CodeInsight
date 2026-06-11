#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  ll N; cin >> N;
  ll res = 0;
  for (ll i = 1; i <= N; i++) {
    res += i * (N + 1 - i);
  }
  for (int i = 0; i < N - 1; i++) {
    ll u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    res -= u * (N + 1 - v);
  }
  cout << res << endl;
}