#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main(void)
{
  ll k;
  cin >> k;
  deque<ll> q;
  if (k < 10)
  {
    cout << k << endl;
    return 0;
  }
  rep(i, 9) q.emplace_back(i + 1);
  k -= 9;
  while (k != 0)
  {
    ll i = q.front();
    q.pop_front();
    for (int j = max(ll(0), i % 10 - 1); j < min(ll(10), i % 10 + 2); ++j)
    {
      q.emplace_back(10 * i + j);
      --k;
      if (k == 0)
      {
        cout << q.back() << endl;
        return 0;
      }
    }
  }
  cout << q.back() << endl;
  return 0;
}