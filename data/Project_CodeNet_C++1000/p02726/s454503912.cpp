#include<bits/stdc++.h>
using namespace std;
#define ll         long long
#define mod        1000000007
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf        1e18
#define ps(x,y)    fixed<<setprecision(y)<<x

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x, y;
	cin >> n >> x >> y;
	int a[n];
	x--; y--;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	std::vector<int> v(n, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int m = min(j - i, min(abs(x - i) + 1 + abs(y - j), abs(x - j) + 1 + abs(y - i)));
			v[m]++;
		}
	}
	for (std::vector<int>::iterator i = v.begin() + 1; i != v.end(); ++i)
	{
		cout << *i << endl;
	}

}