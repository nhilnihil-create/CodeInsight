#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

void addedge(int u, int v){ printf("%d %d\n", u, v); }

int main()
{
	int n = read();
	for (int i = 0; (1 << i) <= n; ++i) 
		if (n == (1 << i)) return puts("No"), 0;
	
	puts("Yes");
	for (int i = 2; i <= n - 1; i += 2)
	{
		addedge(1, i);
		addedge(i, i + 1);
		addedge(1, i + n + 1);
		addedge(i + n + 1, i + n);
	}
	addedge(3, n + 1);
	
	if (n % 2 == 0)
	{
		int j = 0;
		for (int i = 0; (1 << i) <= n; ++i)
			if (n & (1 << i)) j = i;
		addedge(n, ((1 << j) ^ 1) + n);
		addedge(n + n, n ^ (1 << j));
	}
	return 0;
}
