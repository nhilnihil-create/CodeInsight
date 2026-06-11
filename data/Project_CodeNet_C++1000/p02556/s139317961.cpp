#include <bits/stdc++.h>
using namespace std;
long long n;
long long x[1100000],y[1100000],xx[1100000],yy[1100000];
long long ans;
int main()
{
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> x[i] >> y[i],xx[i] = x[i] + y[i],yy[i] = x[i] - y[i];
	sort(xx + 1, xx + 1 + n);
	ans = xx[n] - xx[1];
	sort(yy + 1, yy + 1 + n);
	ans = max(ans, yy[n] - yy[1]);
	cout << ans << endl;
}