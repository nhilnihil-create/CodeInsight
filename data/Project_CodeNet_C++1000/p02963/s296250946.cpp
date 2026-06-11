#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll large = 1000000000;
int main()
{
	ll s;
	cin >> s;

	ll x1 = 1e9;
	if(s > large)
	{
		if(s%x1 == 0)
			cout << x1 << " 0 0 " << s/x1 << " 0 0\n";
		else
			cout << x1 << " 0 " << s%x1 << " " << 1 + s/x1 << " " << "0 1\n";

		// ll sum = x1*(s/x1) + s%x1;
		// cout << sum << "\n";
	}
	else
	{
		cout << s  << " 0 0 1 0 0\n";
	}
}