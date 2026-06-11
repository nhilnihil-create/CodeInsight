/*https://atcoder.jp/contests/abc138/tasks/abc138_c*/
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
	int n, a[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	double sum = a[0];
	for (int i = 1; i < n; i++)
		sum = (sum + a[i]) / 2;
	cout << fixed << setprecision(5) << sum;
}