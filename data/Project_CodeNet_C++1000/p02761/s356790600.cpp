#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)


int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> s(m);
	vector<int> c(m);
	vector<int> ans(n,0);
  ans[0]=1;
	rep(i, m) cin >> s[i] >> c[i];
	bool tf = true;
	if(m==0)
    {
      if(n==1) cout<<0;
      else if(n==2) cout<<10;
      else if(n==3) cout<<100;
    }
  else
  {
        for (int i = 0; i < m; i++)
	{
		for (int t = i + 1; t < m; t++)
		{
			if (s[i] == s[t] && c[i] != c[t]) tf = false;
          if(s[i]==1&&c[i]==0) tf=false;
		}
	}
    
	if (tf == false)
	{
		cout << -1;
	}
	else
	{
		if (n == 1)
		{
			if (m == 0)
			{
				cout << 0;
			}
			else
			{
				cout << c[0];
			}
		}

		else
		{
			rep(i, m)
			{
				ans[s[i] - 1] = c[i];
			}
			if (ans[0] == 0)
			{
				cout << -1;
			}
			else
			{
				rep(i, n)
				{
					cout << ans[i];
				}
			}

		}
	}
  }
	cout << "\n";
  
	return 0;
}