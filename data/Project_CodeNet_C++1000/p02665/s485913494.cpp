#include <bits/stdc++.h>

using namespace std;

const long long INF = 1000000000000000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
	cin >> n;
	vector<long long> A(n + 1);
	vector<long long> lim(n + 1);
	for (int i = 0; i <= n; i++) cin >> A[i];
	lim[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		long long m = (lim[i-1] - A[i-1]) * 2;
		if (m < 0)
		{
		    cout << -1 << '\n';
			return 0;
		}
		lim[i] = min(INF, m);
	}
	if (lim[n] < A[n])
	{
	    cout << -1 << '\n';
		return 0;
	}
    long long ret = A[n];
    long long now = A[n];
	for (int i = n-1; i >= 0; i--)
	{
		now += A[i];
		now = min(now, lim[i]);
		ret += now;
	}
	printf("%lld\n", ret);
	return 0;
}