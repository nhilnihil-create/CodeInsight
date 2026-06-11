#include<cstdio>
int n, m;
char buf[1000100];
int a[1000100];
int b[1000100];
inline int abs(int x) { return x < 0 ? -x : x; }
int exp2(int x)
{
	if (x <= 0) return 0;
	int ret = 0;
	while (!(x & 1)) { x >>= 1; ret++; }
	return ret;
}
int main()
{
	scanf("%d", &n);
	scanf("%s", &buf);
	n--;
	for (int i = 0; i <= n; i++) a[i] = buf[i] - '0';
	for (int i = 0; i < n; i++) b[i] = abs(a[i] - a[i + 1]);
	n--;
	// answer mod 2 = sum of b[i] binom(n, i)
	// if rhs = 1, answer is guaranteed to be 1
	int p2 = 0; // exponent of 2 in binom(n, i)
	int s = 0;
	for (int i = 0; i <= n; i++)
	{
		if (!p2) s ^= b[i];
		p2 += exp2(n - i) - exp2(i + 1);
	}
	if (s & 1)
	{
		printf("1\n");
		return 0;
	}
	// now answer is either 0 or 2
	// in order for the answer to be 2, all b[i] has to be 0 or 2
	// use the same argument as above with b'[i] = b[i]/2
	s = 0;
	bool flag = false;
	p2 = 0;
	for (int i = 0; i <= n; i++)
	{
		if (b[i] == 1) { flag = true; break; }
		if (!p2) s ^= (b[i] / 2);
		p2 += exp2(n - i) - exp2(i + 1);
	}
	if (!flag && (s & 1)) printf("2\n");
	else printf("0\n");
	return 0;
}
