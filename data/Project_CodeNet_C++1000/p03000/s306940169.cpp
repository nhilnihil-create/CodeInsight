#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, x;
	ll sum = 0, cnt = 1;
	scanf("%lld %lld", &n, &x);
	for (int i = 0; i < n; ++i)
	{
		int v;
		scanf("%d", &v);
		sum += v;
		if (sum <= x)
		{
			cnt++;
		}
	}
	printf("%lld\n", cnt);
	return 0;
}