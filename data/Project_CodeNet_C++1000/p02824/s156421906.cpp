#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100005;
inline int readint()
{
	int res = 0, f = 1;
	char c = 0;
	while(!isdigit(c))
	{
		c = getchar();
		if(c=='-')
			f = -1;
	}
	while(isdigit(c))
		res = res*10+c-'0', c = getchar();
	return res*f;
}
int n,m,v,p,a[MAXN];
inline ll calc(ll x, ll y)
	{ return (x-1)/y+1; } 

int main()
{
	n = readint(), m = readint(), v = readint(), p = readint();
	for(int i = 1; i<=n; i++)
	    a[i] = readint();
	sort(a+1,a+n+1), reverse(a+1,a+n+1);
	int ans = p;
	ll sum = 0;
	for(int i = p+1; i<=n; i++)
	{
		if(a[i]+m<a[p])
		    break;
    	if(v<=n-i+p)
		    ans++;
		else if(calc(1ll*(v-n+i-p)*m-sum,i-p)+a[p]<=a[i]+m)
		    ans++;
		sum += a[p]-a[i];
	}
	cout << ans << endl;
	return 0;
}
