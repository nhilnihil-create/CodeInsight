#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[4][4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a[4][4];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	ll ct = 0;
	ll n;
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		ll x;
		cin >> x;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (a[i][j] == x)
					b[i][j] = 1;
	}
	if (b[0][0] * b[1][1] * b[2][2] == 1)
		ct++;
	if (b[0][2] * b[1][1] * b[2][0] == 1)
		ct++;
	for (int i = 0; i < 3; i++)
	{
		if (b[i][0] * b[i][1] * b[i][2] == 1)
			ct++;
		if (b[0][i] * b[1][i] * b[2][i] == 1)
			ct++;
	}
	if (ct > 0)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
