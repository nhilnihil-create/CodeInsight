#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

const int n = 1000000000;
signed main(void)
{
	long long s, x, y;

	cin >> s;
	y = s / n;
	if (s % n != 0) y++;
	x = n * y - s;
	printf("0 0 1000000000 1 %lld %lld\n", x, y);
	return 0;
}
