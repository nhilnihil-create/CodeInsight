/*https://atcoder.jp/contests/abc158/tasks/abc158_b*/
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
	long long a, b, n, r, d, count = 0;
	cin >> n >> a >> b;
	if (n < a + b)
	{
		if ((a == 0 ) || (a == 0 && b == 0))
		{
			cout << count;
			return 0;
		}
		else if (b == 0)
		{
			cout << n;
			return 0;
		}
		else
		{
			cout << min(n, a);
			return 0;
		}
	}
	d = n / (a + b);
	r = n % (a + b);
	count += d * a;
	if (r < a)
		count += r;
	else if (r >= a)
		count += a;
	cout << count;

}