#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	long a[n];
	long s[n];
	long sum = 0;
	rep(i, n)
	{
		cin >> a[i];
		sum += a[i];
		s[i] = sum;
	}
	long ans = labs(sum - a[0] * 2);
	rep(i, n-1)
	{
		// cout << s[i] << endl;
		ans = min(ans, labs(sum - s[i]*2));
	}
	cout << ans;
	return (0);
}
