#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt,sum;
template<typename T>
inline void read(T& x)
{
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
int main()
{
	int n,d;ll c;
	read(n);
	while(n--)
	{
		read(d),read(c);
		cnt+=c,sum+=c*d;
	}
	printf("%lld\n",cnt-1+(sum-1)/9);
	return 0;
}