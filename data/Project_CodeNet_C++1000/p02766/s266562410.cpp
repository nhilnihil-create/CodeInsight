#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

long digit(long n, long k)
{
	long cnt = 1;
	while (n >= k)
	{
		n /= k;
		cnt++;
	}
	return cnt;
}

int  main()
{
	long n;
	long k;
	cin >> n >> k;
	long ans = digit(n, k);
	cout << ans << endl;
	return (0);
}