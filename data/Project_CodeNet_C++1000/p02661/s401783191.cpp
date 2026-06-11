#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[200001], b[200001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);	
	if (n % 2 == 1)
	{
		int me_a = a[(n + 1) / 2], me_b = b[(n + 1) / 2];
		cout << (me_b - me_a + 1) << '\n';
	}
	else
	{
		int me_a = (a[n / 2] + a[n / 2 + 1]) / 2, me_b = (b[n / 2] + b[n / 2 + 1]) / 2;
		if ((a[n / 2] + a[n / 2 + 1]) % 2 && (b[n / 2] + b[n / 2 + 1]) % 2)
			cout << (me_b - me_a) * 2 + 1 << '\n';
		else if ((a[n / 2] + a[n / 2 + 1]) % 2)	
			cout << (me_b - me_a) * 2 << '\n';
		else if ((b[n / 2] + b[n / 2 + 1]) % 2)
			cout << (me_b - me_a) * 2 + 2 << '\n';
		else
			cout << (me_b - me_a) * 2 + 1 << '\n';				
	}
}