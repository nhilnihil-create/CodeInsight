#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, q;
vector<ll> a, b, c, d;

ll score(vector<ll> &A)
{
  ll res = 0;
  for (ll i = 0; i < q; i++)
  {
    if (A[b[i]] - A[a[i]] == c[i])
    {
      res += d[i];
    }
  }
  return res;
}

ll dfs(vector<ll> &A)
{
  if (A.size() == n)
  {
    return score(A);
  }
  ll res = 0;
  ll prev_last = A.empty() ? 0 : A.back();
  for (ll i = prev_last; i < m; i++)
  {
    A.push_back(i);
    res = max(res, dfs(A));
    A.pop_back();
  }
  return res;
}

int main()
{
  cin >> n >> m >> q;
  a = b = c = d = vector<ll>(q);
  for (ll i = 0; i < q; i++)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i];
    --b[i];
  }
  vector<ll> A;
  cout << dfs(A) << endl;
}
