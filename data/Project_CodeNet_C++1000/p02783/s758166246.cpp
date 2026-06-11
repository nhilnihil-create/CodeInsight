#include "bits/stdc++.h"

using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int main()
{
  IOS;
  int h,a ;
  cin >> h >> a;
  if (a>h)
    cout << 1 << endl;
  else
    {
      int ans=0;
      int q=h;
      for (int i=0; i<q; i++)
	{
	  h-=a;
	  if (h<=0)
	    break;
	  else
	    ans++;
	}
      cout << ans+1 << endl;
    }
  return 0;
}
