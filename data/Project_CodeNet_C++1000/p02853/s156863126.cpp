#include <bits/stdc++.h>
     
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x,y;
	int res = 0;
	cin >> x >> y;

	if(x==1)
	{
		res += 3e5;
	}
	else if(x==2)
	{
		res += 2e5;
	}
	else if(x==3)
	{
		res += 1e5;
	}
	if(y==1)
	{
		res += 3e5;
	}
	else if(y==2)
	{
		res += 2e5;
	}
	else if(y==3)
	{
		res += 1e5;
	}

	if(x==1 && y==1)
	{
		res += 4e5;
	}

	cout << res << '\n';

	return 0;
}