#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn];
int n, ans;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		ans ^= a[i];
	}
	for(int i = 1; i <= n; ++i) cout << (ans ^ a[i]) << ' ';
	cout << endl;
	return 0;
}
 