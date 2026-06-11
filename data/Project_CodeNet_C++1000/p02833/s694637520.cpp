#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin>>n;

	if(n%2!=0)
		cout<<0;

	else
	{
		long long ans=0,div=10;
		while(div <= n)
		{
			ans+=(n/div);
			div*=5;
		}

		cout<<ans;
	}
	return 0;
}