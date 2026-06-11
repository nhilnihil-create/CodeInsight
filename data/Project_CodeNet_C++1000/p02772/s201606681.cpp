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
  for (int i=0; i<n; i++)
    {
      if (arr[i]%2==0)
	{
	  if (arr[i]%3==0 || arr[i]%5==0)
	    {
	      continue;
	    }
	  else
	    {
	      cout << "DENIED" << endl;
	      return 0;
	    }
	}
    }
  cout << "APPROVED" << endl;
  return 0;
}
