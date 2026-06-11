#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,n;
int main() {
	scanf("%lld%lld%lld",&a,&b,&n);
	ll x=min(b-1,n);
	printf("%lld\n",a*x/b-a*(x/b));
//	for (register int i=1;i<=n;++i)
//		printf("%d: %d\n",i,a*i/b-a*(i/b));
	return 0;
}