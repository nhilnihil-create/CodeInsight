#include <bits/stdc++.h>

using std::pair;
const int N = 1e6 + 5;
int n, tot, a[N]; 
char s[N];

int main()
{
	scanf("%d%s", &n, s);
	--n;
	for (int i = 0; i <= n; ++i)
		a[i] = s[i] - '0' - 1;
	for (int i = 0; i <= n; ++i)
		if ((n & i) == i)
			tot = tot + a[i] & 1;
	if (tot)
		puts("1");
	else
	{
		bool flag = false;
		for (int i = 0; i <= n; ++i)
			if (a[i] == 1)
			{
				puts("0");
				flag = true;
				break ;
			}
		if (!flag)
		{
			tot = 0;
			for (int i = 0; i <= n; ++i)
				if ((n & i) == i)
					tot = tot + (a[i] >> 1) & 1;
			printf("%d\n", tot << 1);
		}
	}
}