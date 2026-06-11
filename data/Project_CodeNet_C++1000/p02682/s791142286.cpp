#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	
	
	if(k<=a)
	{
		cout << k << "\n";
	}
	else if(k<=a+b)
	{
		cout << a << "\n";
	}
	else 
	{
		cout << a-(k-a-b) << "\n";
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
