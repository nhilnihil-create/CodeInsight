#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
	int n, a, b;
	cin>>n>>a>>b;
	if(a > b)
		swap(a,b);
	int ans, count = 0;
	if(a==b)
		ans = 0;
	else if((b-a)%2==0)
	{
		ans = (b-a)/2;
	}
	else
	{
		if(b-a == 1)
			ans = min(b-1, n-a);
		else
		{
			if(a-1>n-b)
			{
				ans = n-b+1 + (b-a-1)/2;
			}
			else
				ans = a+ (b-a-1)/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}