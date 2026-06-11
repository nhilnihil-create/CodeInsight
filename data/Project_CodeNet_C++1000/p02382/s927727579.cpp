#include <iostream>
#include <cmath>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	int n;
	cin >> n;
	double a[101],b[101];
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];

	double ans;
	rep(i,3)
	{
		ans = 0;
		rep(j,n)
		{
			ans += pow(fabs(a[j]-b[j]),i+1);
		}
		ans = pow(ans,1.0/(i+1));
		cout << fixed;
		cout.precision(8);
		cout << ans << endl;
	}
	ans = 0;
	rep(i,n)
	{
		ans  = max(ans,fabs(a[i] - b[i]));
	}
	cout << fixed;
	cout.precision(8);
	cout << ans << endl;
	return 0;
}