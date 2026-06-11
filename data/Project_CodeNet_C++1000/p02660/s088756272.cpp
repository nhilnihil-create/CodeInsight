#include <bits/stdc++.h>
using namespace std;

int cntDistincts(int n)
{
	long long int start = 1;
	int ret = 0;
	while(true)
	{
		long long int total = (start*(start+1))/2;
		if(total <= n)
		{
			++ret;
		}
		else
			break;
		++start;
	}
	return ret;
}

int main()
{
	long long int n; cin >> n;
	long long int p = 2;
	int ans = 0;
	for(; p*p <= n; ++p)
	{
		if((n%p) == 0)
		{
			int cnt = 0;
			while((n%p) == 0)
			{
				n /= p;
				++cnt;
			}
			ans += cntDistincts(cnt);
		}
	}
	if(n!= 1) ++ans;

	cout << ans;

	return 0;
}