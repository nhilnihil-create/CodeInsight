#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5010;
int k,q,d[MAXN],n;
ll x,m,sum,ans,tmp[MAXN];
int main () {
	scanf("%d%d",&k,&q);
	for (int i=1;i<=k;i++) {scanf("%d",&d[i]);}
	for (int i=1;i<=q;i++) {
		scanf("%d%lld%lld",&n,&x,&m);
		for (int j=1;j<=k;j++) {
			tmp[j]=d[j]%m;
			if (!tmp[j]) {tmp[j]=m;}
			tmp[j]+=tmp[j-1];
		}
		x=x%m+tmp[k]*((n-1)/k)+tmp[(n-1)%k];
		printf("%lld\n",n-1-x/m);
	}
	return 0;
}