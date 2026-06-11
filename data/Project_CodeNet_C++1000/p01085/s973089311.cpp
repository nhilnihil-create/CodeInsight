#include <bits/stdc++.h>
using namespace std;
const double eps=1e-9;
typedef vector<int> vi;
typedef long long ll;
int m,nmn,nmx;
int gap=0;
int p[10005];
int main(void)
{
  while(cin >> m >> nmn >> nmx && m)
    {
      int ans;
      gap=0;
      for(int i=1;i<=m;i++)
	{
	  cin >> p[i];
	}
      for(int i=nmn;i<=nmx;i++)
	{
	  int tmp;
	  tmp=p[i]-p[i+1];
	  if(tmp>=gap)
	    {
	      gap=tmp;
	      ans=i;
	    }
	}
      cout << ans << endl;
    }
  return 0;
}

