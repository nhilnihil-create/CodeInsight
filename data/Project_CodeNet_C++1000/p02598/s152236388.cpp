#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
bool check(int x, vector<int> &v, int k)
{
  int cuts = 0;
  for (int i = 0; i < v.size(); i++)
  {
    cuts += v[i] / x;
    if (v[i] % x == 0)
      cuts--;
  }
  if (cuts <= k)
    return true;
  else
    return false;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  int low = 1;
  int high = 1000000000;
  for (int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }
  int ans;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (check(mid, v, k))
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  cout << ans ;
}
