/*https://atcoder.jp/contests/abc156/tasks/abc156_c*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	// for getting input from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif
	int n, a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int sum = 0, min_sum = 1e9, mina = a[0], max = a[n - 1];
	// cout << min << max << endl;
	for (int i = mina; i <= max; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
			sum += (a[j] - i) * (a[j] - i);
		min_sum = min(min_sum, sum);
	}
	cout << min_sum << endl;
}