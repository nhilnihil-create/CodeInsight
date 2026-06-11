/*https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b*/
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
	long long n, m;
	cin >> n >> m;
	if (n == 1 || m == 1)
	{
		cout << "1";
	}
	else if (n * m % 2 != 0)
		cout << n*m / 2 + 1;
	else
		cout << n*m / 2;
}