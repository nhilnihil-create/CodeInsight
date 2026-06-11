/*https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b*/
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
	for (int i = 0; i <= n; i++)
	{
		if (int(i * 1.08) == n)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
}