#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int maxN = 505, lim = 61;

int n, T;
LL a[maxN + 1], p[maxN + 1];
char s[maxN + 1];

inline void insert(LL x)
{
	for(int i = lim; i >= 0; i--)
		if(x & (1ll << i))
		{
			if(p[i]) x ^= p[i];
			else
			{ 
				p[i] = x; 
				break; 
			}
		}
}

inline bool check(LL x)
{
	for(int i = lim; i >= 0; i--)
		if(x & (1ll << i)) x ^= p[i];
	return x == 0;
}

int main()
{
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		
		for(int i = 0; i <= lim; i++) p[i] = 0;
		scanf("%s", s + 1);

		bool flag = true;
		for(int i = n; i >= 1; i--)
			if(s[i] == '0') insert(a[i]);
			else if(!check(a[i])) { flag = false; break; }
		
		puts(flag ? "0" : "1");
	}
	return 0;
}
