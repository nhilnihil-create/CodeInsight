#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n, a[N], ans, ma, mx[N];
int main()
{
    std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx[i] = max(mx[i - 1], a[i - 1]);
	}
	for(int i = 1; i <= n; i++) ans += max(0LL, mx[i] - a[i]);
	cout << ans << endl;
	return 0;
}