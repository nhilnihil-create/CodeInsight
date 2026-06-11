#include<bits/stdc++.h>
#define int long long
#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int32_t main()
{

	int a, b;
	cin >> a >> b;
	int ans = 0, outelt = 1;

	while (outelt < b)
	{
		--outelt;
		outelt += a;
		++ans;
	}
	cout << ans << endl;
}
