/*https://atcoder.jp/contests/abc141/tasks/abc141_c*/
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
	int n, pos, q;
	long long k;
	cin >> n >> k >> q;
	int a[n];
	for (int i = 0; i < n; i++)
		a[i] = k - q;
	while (q--)
	{
		cin >> pos;
		pos--;
		a[pos]++;
	}
	for (int i = 0; i < n; i++)
	{
		// cout << a[i] << "->";
		if (a[i] <= 0)
			cout << "No" << "\n";
		else
			cout << "Yes" << "\n";
	}
}