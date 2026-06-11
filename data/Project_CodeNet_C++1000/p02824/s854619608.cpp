#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, M, V, P;
vector<ll> A;
bool check(ll m)
{
  if (A.at(m) + M < A.at(P - 1))
  {
    return false;
  }
  ll s = 0;
  s += M * (P - 1 + N - m);
  for (int i = P - 1; i < m; ++i)
  {
      s += max(0ll, A.at(m) + M - A.at(i));
  }
  if (s >= M * V)
  {
    return true;
  }
  return false;
}


int main()
{
  cin >> N >> M >> V >> P;
  A = vector<ll>(N);
  for (ll i = 0; i < N; ++i)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  // cout << "A" << endl;
  // for (ll i = 0; i < N; ++i)
  // {
  //   cout << A.at(i) << ' ';
  // }
  // cout << endl;
  ll l = -1, r = N;
  ll m;
  while (l + 1 != r)
  {
    m = (l + r) / 2;
    if (check(m))
    {
      l = m;
    }
    else
    {
      r = m;
    }
  }
  cout << l + 1 << endl;
  // cout << "l" << l << endl;
}
