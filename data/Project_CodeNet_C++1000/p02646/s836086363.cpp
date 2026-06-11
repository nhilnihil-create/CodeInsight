// Created by: WeirdBugsButOkay

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ff first
#define ss second
#define PI 3.14159265358979323846
#define endl '\n'

using namespace std;

ll ceil(ll a, ll b)
{
	return (a + b - 1) / b;
}

void solve()
{
	ll a, b, v, w, t;
	cin >> a >> v >> b >> w >> t;
	if(v <= w)
		cout << "NO" << endl;
	else
	{
		ll d = abs(b - a);
		ll sc = abs(v - w);
		if(ceil(d, sc) <= t)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main()
{
	int q = 1;
	//scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		solve();
	}
	return 0;
}