#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int n; cin >> n;
	cout << ceil((n * 1.0) / 2) << endl;
	return 0;
}
