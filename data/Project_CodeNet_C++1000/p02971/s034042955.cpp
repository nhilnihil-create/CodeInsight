/*https://atcoder.jp/contests/abc134/tasks/abc134_c*/
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
	int a[n], max_a, b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];
	sort(b, b + n);
	reverse(b, b + n);
	int pos1, pos2;
	for (int i = 0; i < n; i++)
		if (a[i] == b[0])
			pos1 = i;
		else if (a[i] == b[1])
			pos2 = i;
	for (int i = 0; i < n; i++)
	{
		if (i == pos1)
			cout << b[1] << endl;
		else
			cout << b[0] << endl;
	}
}