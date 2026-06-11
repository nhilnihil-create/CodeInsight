#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
#include <vector>

using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
	int n=read();
	if (!(n&(n-1))) 
		puts("No");
	else
	{
		puts("Yes");
		puts("1 2");
		puts("2 3");
		cout << 3 << " " << n+1 << endl;
		cout << n+1 << " " << n+2 << endl;
		cout << n+2 << " " << n+3 << endl;
		for (int i=4;i+1<=n;i+=2)
		{
			int j=i+1;
			cout << 1 << " " << i << endl;
			cout << 1 << " " << j << endl;
			cout << i << " " << j+n << endl;
			cout << j << " " << i+n << endl;
		}
		if (n%2==0)
		{
			for (int i=4;i<=n;i++)
			{
				int j=n^i^1;
				if (j!=3 && j<n)
				{
					cout << i << " " << n << endl;
					cout << j << " " << 2*n << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}