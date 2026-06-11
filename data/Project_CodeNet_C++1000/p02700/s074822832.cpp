#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	while(true) 
	{
		c -= b;
		if(c <= 0)
		{
			cout << "Yes\n";
			return ;
		}
		a -= d;
		if(a <= 0)
		{
			cout << "No\n";
			return ;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
