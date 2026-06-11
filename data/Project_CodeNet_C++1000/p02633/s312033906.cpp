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
void print(int x)
{
	if (x >= 10)
		print(x / 10);
	putchar('0' + x % 10);
}
void write(int x, char c)
{
	if (x < 0)
		putchar('-'), x = -x;
	print(x);
	putchar(c);
}
int lcm(int x, int y)
{
	return x / __gcd(x, y) * y;
}
int main()
{
	int x = read();
	int k = lcm(360, x);
	if ((k / 360) & 1)
		write(k / x, '\n');
	else
		write(lcm(720, x) / x, '\n');
	return 0;
}
