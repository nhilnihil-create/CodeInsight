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
	if (a > b)
	{
		for (int i = 0; i < a; ++i)
		{
			cout<<b;
		}
		cout<<endl;
	}
	else if (a < b)
	{
		for (int j = 0; j < b; ++j)
		{
			cout<<a;
		}
		cout<<endl;
	}
	else
	{
		for (int k = 0;k < b; ++k)
		{
			cout<<a;
		}
		cout<<endl;
	}
	return 0;
}