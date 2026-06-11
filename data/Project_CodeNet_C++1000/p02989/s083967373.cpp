/*https://atcoder.jp/contests/abc132/tasks/abc132_c*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int count = 0;
	// cout << a[n / 2 ] << " " << a[n / 2 - 1];
	if (n % 2 == 0 && a[n / 2 ] != a[n / 2 - 1])
		count = a[n / 2 ] - a[n / 2 - 1];
	cout << count;
}