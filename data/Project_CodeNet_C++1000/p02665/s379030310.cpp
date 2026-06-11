#include "iostream"
#include "vector"
#include "cmath"

using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;

  vector<ll> as(n + 1, 0);
  for (ll i = 0; i <= n; i++)
    cin >> as[i];

  vector<ll> sums(n + 1, 0);
  // cout << "sums: ";
  for (ll i = n; i >= 0; i--)
  {
    if (i == n)
      sums[i] = as[i];
    else
      sums[i] = as[i] + sums[i + 1];

    // cout << sums[i];
  }
  // cout << endl;

  // cout << "as: ";
  // for (auto i = 0; i <= n; i++)
  // {
  //   cout << as[i] << " ";
  // }
  // cout << endl;

  if (n == 0)
  {
    if (as[0] == 1)
    {
      cout << 1 << endl;
      return 0;
    }
    else
    {
      cout << -1 << endl;
      return 0;
    }
  }

  if (as[0] != 0)
  {
    cout << -1 << endl;
    return 0;
  }

  // 以下は深さ1以上.
  ll cnt = 1;
  ll last_has_child = 1;
  for (ll i = 1; i <= n; i++)
  {
    ll cap = min(2 * last_has_child, sums[i]);
    if (as[i] > cap)
    {
      cout << -1 << endl;
      return 0;
    }

    ll has_child = min(cap - as[i], sums[i]);
    // printf("i: %lld, child: %lld, leaf: %lld\n", i, has_child, as[i]);
    cnt += has_child + as[i];
    last_has_child = has_child;
  }

  cout << cnt << endl;

  return 0;
}
