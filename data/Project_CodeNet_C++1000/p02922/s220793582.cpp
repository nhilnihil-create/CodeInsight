#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin>>a>>b;
	int c = 1, ans = 0;
	while(c<b)
	{
		c--;
		c += a;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}