#include <bits/stdc++.h> 
 
using namespace std; 

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	long long int n;

	cin >> n;

	long long int res = 1e18;
	for(long long int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			long long int a = i;
			long long int b = n/i;
			res = min(res,a+b-2);
		}
	}

	cout << res << '\n';
	
	return 0;
}