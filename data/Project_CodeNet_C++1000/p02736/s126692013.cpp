#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(a, b) make_pair(a, b)
#define ls (rt << 1)
#define rs (rt << 1 | 1) 
typedef pair<int, int> pii; 
const ll mod = 1e9 + 7;
template <class T> T lowbit(T x){return ((x)&(-(x)));}
const int maxn = 1e6 + 10;
int t, n, m;
char s[maxn];
bool f(int x)
{
	for(int i = 30; ~i; --i)
		if((x & (1 << i)) && !((n - 1) & (1 << i)))
			return 0;
	return 1;
}
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	int ret = 0, tot = 0;
	for(int i = 0; i < n; ++i)
	{
		--s[i];
		if(s[i] == '1')
			++tot;
		if(!f(i)) continue;
		if(s[i] == '1') 
			ret ^= 1;
	}
	if(ret) puts("1");
	else if(tot) puts("0");
	else
	{
		ret = 0;
		for(int i = 0; i < n; ++i)
		{
			if(!f(i)) continue;
			if(s[i] == '2') 
				ret ^= 1;
		}
		if(ret) puts("2");
		else puts("0");
	}
	return 0;
}