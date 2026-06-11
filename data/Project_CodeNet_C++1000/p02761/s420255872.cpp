#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n, -1);
	for (int i = 0; i < m; ++i)
	{
		int c, s;
		cin >> c >> s;
		c --;
		if (a[c] == -1)
			a[c] = s;
		else if (a[c] != s)
			return cout << -1, 0;
	}
	if (n == 1)
	{
		if (a[0] == -1)
			a[0] = 0;
		cout << a[0];
		return 0;
	}
	if (a[0] == 0)
		return cout << -1, 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == -1)
		{
			if (i)
				a[i] = 0;
			else
				a[i] = 1;
		}
		cout << a[i];
	}
	return 0;
}