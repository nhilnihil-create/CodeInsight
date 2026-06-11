#include <bits/stdc++.h>

using namespace std;

inline int gi()
{
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

int a, b, c, d;

int main()
{
	a = gi(), b = gi(), c = gi(), d = gi();
	if (d == 1) puts("1");
	else puts("0");
	return 0;
}
