#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005], b[100005];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i % 2 == 1)b[1] += a[i];
		else b[1] -= a[i];
	}
	cout << b[1];
	for (int i = 2; i <= n; i++)
	{
		b[i] = 2 * a[i - 1] - b[i - 1];
		cout << " " << b[i];
	}
	return 0;
} 