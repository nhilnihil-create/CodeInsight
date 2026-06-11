#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD (1000000007)

int arr[2010][2010] = {};

ll comb(ll n, ll r)
{
  if (n < 0 || r < 0)
    cout << n << "," << r << endl;
  if (arr[n][r] != 0)
    return arr[n][r];
  else if (r == 0)
  {
    arr[n][r] = 1;
    return arr[n][r];
  }
  else if (r == 1)
  {
    arr[n][r] = n;
    return arr[n][r];
  }
  else if (n <= r)
  {
    arr[n][r] = 1;
    return arr[n][r];
  }
  else
  {
    arr[n][r] = (comb(n - 1, r - 1) + comb(n - 1, r)) % MOD;
    return arr[n][r];
  }
}

int main()
{
  ll n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++)
  {
	if (n-k+1 < i)
      cout << 0 << endl;
    else
    cout << (comb(n - k + 1, i) * comb(k - 1, i - 1)) % MOD << endl;
  }
}
