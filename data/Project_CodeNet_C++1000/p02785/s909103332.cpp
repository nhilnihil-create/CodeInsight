#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  ll n, k;
  cin >> n >> k;
  ll arr[n];
  for (int i=0; i<n; i++)
    {
      cin >> arr[i];
    }
  sort (arr, arr+n);
  ll ans=0;
  if (n>k)
    {
      for (int i=0; i<n-k; i++)
	{
	  ans+=arr[i];

	}
    }
  cout << ans << endl;
  return 0;
}
