/*https://atcoder.jp/contests/abc161/tasks/abc161_c*/
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
	long long n, k, e, dif;
	cin >> n >> k;
	e = n % k;
	dif = abs(e - k);
	cout << min(dif, e);
}