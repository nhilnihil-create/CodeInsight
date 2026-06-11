#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  int n;
  cin >> n;
  int arr[n];
  for (int i=0; i<n; i++)
    {
      cin >> arr[i];
    }
  int ans=1;
  int q=arr[0];
  for (int i=1; i<n; i++)
    {
      if (arr[i]<q)
	{
	  q=arr[i];
	  ans++;
	}
    }
  cout << ans << endl;
  return 0;
}
