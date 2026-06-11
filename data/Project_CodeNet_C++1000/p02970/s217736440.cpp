#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, d; cin >> n >> d;
	long long int sum = d * 2 + 1;
	sum = ceil((double)n / sum);
	cout << sum << endl;
	return 0;
}