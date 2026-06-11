#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  ll most = (N - 1) * (N - 2) / 2;
  if (K > most) {
    cout << -1 << "\n";
    return 0;
  }
  ll M = N - 1 + most - K;
  cout << M << "\n";
  for (ll i = 1; i < N; ++i) {
    cout << 1 << ' ' << i + 1 << "\n";
  }
  vector<ll> node(N - 1);
  for (ll i = 0; i < N - 1; ++i) {
    node.at(i) = i + 2;
  }
  ll cnt = 0;
  for (ll i = 0; i < N - 2; ++i) {
    for (ll j = i + 1; j < N - 1; ++j) {
      if (cnt == most - K) {
        return 0;
      }
      cout << node.at(i) << ' ' << node.at(j) << "\n";
      cnt += 1;
    }
  }
}
