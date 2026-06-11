#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn];
int main()
{
	int n;
	ll ans, m, sum = 0;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (n == 0 && a[0] != 1 || (n > 0 && a[0] == 1))
	{
		cout<<-1<<endl;
		return 0;
	}
	ans = 1;
	m = 1;
	for (int i = 1; i <= n; i++)
	{
		m = min(m * 2, sum);
		if (a[i] > m)
		{
			cout << -1 << endl;
			return 0;
		}
		ans += m;
		m -= a[i];
		sum -= a[i];
	}
	cout << ans << endl;
	return 0;
}