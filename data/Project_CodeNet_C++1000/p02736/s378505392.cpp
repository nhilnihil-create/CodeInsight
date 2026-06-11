//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out = 0, fh = 1;
	char jp = getchar();
	while ((jp > '9' || jp < '0') && jp != '-')
		jp = getchar();
	if (jp == '-')
		fh = -1, jp = getchar();
	while (jp >= '0' && jp <= '9')
		out = out * 10 + jp - '0', jp = getchar();
	return out * fh;
}
const int N = 1e6 + 10;
char s[N];
int n, a[N];
int solve()
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == 1)
			ans ^= ((n - 1) & i) == i;
	if (ans == 1)
		return 1;
	bool f = true;
	for (int i = 0; i < n; ++i)
		if (a[i] == 1)
			return 0;
		else
			f &= (!a[i]), a[i] >>= 1;
	if (f)
		return 0;
	return solve() * 2;
}
int main()
{
	n = read();
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		a[i] = s[i] - '1';
	printf("%d\n", solve());
	return 0;
}
