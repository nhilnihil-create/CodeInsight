/*https://atcoder.jp/contests/abc153/tasks/abc153_d*/
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
	long long h, count = 0 , a, i;
	cin >> h;
	a = h;
	if (h > 1)
		h /= 2, count ++, i = 2;
	while (h > 1)
	{
		// cout << h << "->" << i << ":" << count << endl;
		h /= 2, count += i * 1, i *= 2;

	}
	if (h == 1 && a > 1)
		count += i * 1;
	else if (h == 1 && a <= 1)
		count++;
	cout << count;

}