#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << "\n"
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
typedef long long ll;

int binary_search(ll a[], ll k, int e)
{
  int left = 0;
  int right = e - 1;
  int mid;
  while (left <= right)
  {
    mid = (right + left) / 2;
    if (a[mid] == k)
    {
      return mid;
    }
    else if (a[mid] < k)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return right;
}

int main()
{
  int n, m;
  ll k;
  cin >> n >> m >> k;

  ll a[n];
  ll b[m];

  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;

    if (i == 0)
    {
      a[i] = t;
    }
    else
    {
      a[i] = a[i - 1] + t;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int t;
    cin >> t;
    if (i == 0)
    {
      b[i] = t;
    }
    else
    {
      b[i] = b[i - 1] + t;
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++)
  {
    int acount = i;
    ll atotal;
    if (i == 0)
    {
      atotal = 0;
    }
    else
    {
      atotal = a[i - 1];
    }
    if (atotal > k)
    {
      continue;
    }

    int bcount = 0;
    if ((k - atotal) >= b[0])
    {
      bcount = binary_search(b, k - atotal, m) + 1;
    }
    if (ans < acount + bcount)
    {
      ans = acount + bcount;
    }
  }

  cout << ans << endl;
}
