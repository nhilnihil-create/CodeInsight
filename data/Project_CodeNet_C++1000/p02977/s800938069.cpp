#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
inline int read()
{
	register int x = 0 , f = 0; register char c = getchar();
	while(c < '0' || c > '9') f |= c == '-' , c = getchar();
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0' , c = getchar();
	return f ? -x : x;
}
int n;
int main()
{
	n = read();
	if(!(n & (n - 1))) puts("No");
	else
	{
		puts("Yes");
		puts("1 2");
		puts("2 3");
		cout << 3 << " " << n+1 << '\n';
		cout << n+1 << " " << n+2 << '\n';
		cout << n+2 << " " << n+3 << '\n';
		for(int i = 4 ; i + 1 <= n ; i += 2)
		{
			int j=i+1;
			cout << 1 << " " << i << '\n';
			cout << 1 << " " << j << '\n';
			cout << i << " " << j+n << '\n';
			cout << j << " " << i+n << '\n';
		}
		if(n%2==0)
		{
			for(int i = 4 ; i <= n ; ++i)
			{
				int j = n ^ i ^ 1;
				if (j != 3 && j < n)
				{
					cout << i << " " << n << '\n';
					cout << j << " " << 2*n << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}