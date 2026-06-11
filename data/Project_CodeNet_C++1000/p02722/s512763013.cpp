#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<pll> part(ll N)
{
  vector<pll> res;
  ll temp = N;
  for (ll i = 2; i * i <= temp; ++i) {
    if (N % i == 0) {
      ll cnt = 0;
      while (N % i == 0) {
        N /= i;
        cnt += 1;
      }
      res.push_back({i, cnt});
    }
  }
  if (N != 1) {
    res.push_back({N, 1});
  }
  return res;
}

ll num_part(ll N)
{
  ll res = -1;
  for (ll i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res += 2;
    }
    if (i * i == N) {
      res -= 1;
    }
  }
  return res;
}

int main()
{
  ll N;
  cin >> N;
  ll ans = num_part(N - 1) + 1;
  // cout << ans << endl;
  for (ll i = 2; i * i <= N; ++i) {
    if (N % i != 0) {
      continue;
    }
    ll temp = N;
    while (temp % i == 0) {
      temp /= i;
    }
    if (temp % i == 1) {
      ans += 1;
    }
  }
  cout << ans << endl;
}
