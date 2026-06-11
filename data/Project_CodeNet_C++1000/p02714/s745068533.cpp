#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; string s;
	cin >> n >> s;
	ll r=0,g=0,b=0;
	for (auto c : s)
	{
		if (c == 'R') r++;
		else if (c == 'G') g++;
		else b++;
	}
	ll all = r*g*b;
	ll minus=0;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
		{
			if (s[i] == s[j]) continue;
			ll k = j*2-i;
			if (k >= n || s[k] == s[i] || s[k] == s[j])
				continue;
			minus++;
		}
	cout<<all-minus<<"\n";

	return 0;
}