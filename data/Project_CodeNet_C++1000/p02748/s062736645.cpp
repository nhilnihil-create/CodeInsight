/*https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_b*/
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
	int n, l, m;
	long long min_cost = 1e9 + 1, cost = 0;
	cin >> n >> l >> m;
	int a[n], b[l], c[m], x[m], y[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < l; j++)
		cin >> b[j];
	for (int i = 0; i < m; i++)
		cin >> x[i] >> y[i] >> c[i];
	for (int i = 0; i < m; i++)
	{
		cost = a[x[i] - 1] + b[y[i] - 1] - c[i];
		// cout << cost << endl;
		min_cost = min(min_cost, cost);
	}
	n = min(n, l);
	int minR = 1e5 + 1, minM = 1e5 + 1;
	for (int i = 0; i < n; i++)
		minR = min(a[i], minR);
	for (int i = 0; i < l; i++)
		minM = min(b[i], minM);
	cost = minM + minR;
	min_cost = min(min_cost, cost);
	cout << min_cost;
}