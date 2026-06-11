#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,i,l,r,mid,sum[N],c[N],x;
signed main(){
	scanf("%lld",&n);
	for (i=1;i<=n;i++) 
		scanf("%lld",&x), ++sum[++c[x]];
	for (i=1;i<=5e5;i++) sum[i]+=sum[i - 1];
	for (i=1;i<=n;i++){
		l = 1, r = 4e5;
		while (l <= r) {
			mid = (l + r) >> 1;
			(mid * i <= sum[mid])? l = mid + 1: r = mid - 1;
		}
		printf("%lld\n", l - 1);
	} return 0;
}
