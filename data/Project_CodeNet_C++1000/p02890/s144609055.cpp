#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,i,l,r,mid,ans,sum[N],c[N],x;
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&x),++sum[++c[x]];
	for (i=1;i<=n + 5;i++) sum[i]+=sum[i-1];
	for (i=1;i<=n;i++){
		l=1,r=n + 5,ans=0;
		while (l<=r){
			mid=l+r>>1;
			if (1ll*mid*i<=sum[mid]) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}