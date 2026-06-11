#include <bits/stdc++.h>
using namespace std;
const int size = 51;
int a[size];
int main ()
{
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			ans += a[i] * a[j];
		}
	cout << ans << '\n';
}
