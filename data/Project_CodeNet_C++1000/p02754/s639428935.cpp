#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int n, a, b; cin >> n >> a >> b;
	cout << (n / (a + b))*a + min(a, n % (a + b)) << endl;
	return 0;

}
