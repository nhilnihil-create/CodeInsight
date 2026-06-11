#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i *= 2)
		if (i == n) { cout << "No" << endl; return 0; }
	cout << "Yes" << endl;
	cout << "1 2\n2 3\n";
	cout << 3 << ' ' << n + 1 << endl;
	cout << n + 1 << ' ' << n + 2 << endl;
	cout << n + 2 << ' ' << n + 3 << endl;
	for (int i = 4; i + 1 <= n; i += 2)
	{
		printf("%d %d\n", i, i + 1);
		printf("%d %d\n", n + 1, i + 1);
		printf("%d %d\n", n + i, n + i + 1);
		printf("%d %d\n", n + 1, n + i);
	}
	if (!(n & 1))
	{
		int i = 1;
		while (i * 2 <= n)i *= 2;
		cout << n << ' ' << n+i << endl;
		i ^= n ^ 1;
		cout << n + n << ' ' << i << endl;
	}
	return 0;
}