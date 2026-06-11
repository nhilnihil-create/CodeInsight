#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;


int main()
{
  ll N, K;
  cin >> N >> K;
  ll M = (N - 1) * (N - 2) / 2;
  if (K > M)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << (N - 1) + (M - K) << endl;
  for (ll i = 2; i <= N; ++i)
  {
    cout << 1 << ' ' << i << endl;
  }
  if (M == K)
  {
    return 0;
  }
  ll cnt = 0;
  for (ll i = 2; i <= N - 1; ++i)
  {
    for (ll j = i + 1; j <= N; ++j)
    {
      cout << i << ' ' << j << endl;
      cnt += 1;
      if (cnt == M - K)
      {
        return 0;
      }
    }
  }
}
