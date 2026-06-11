/*https://atcoder.jp/contests/abc139/tasks/abc139_b*/\
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
	int a, b;
	cin >> a >> b;
	int count = 0, out = 1;
	while (out < b)
	{
		out--;
		out += a;
		count++;
	}
	cout << count;
}