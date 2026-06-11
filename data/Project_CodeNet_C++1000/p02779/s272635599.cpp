#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  ll n;
  cin >> n;
  vector<ll> arr;
  for (int i=0, x; i<n; i++)
    {
      cin >> x;
      arr.push_back(x);
    }
  sort(arr.begin(), arr.end());
  for (int i=0; i<n-1; i++)
    {
      if (arr[i]==arr[i+1])
	{
	  cout << "NO" << endl;
	  return 0;
	}
    }
  cout << "YES" << endl;
  return 0;
}
