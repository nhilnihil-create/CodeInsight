#include<bits/stdc++.h>
using namespace std;

const int maxn=505;
int a[maxn],s,r[maxn],sum[maxn],ans,n,k;

int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i) {
		scanf("%d",a+i);
		s+=a[i];
	}
	for(int i=1;i<=sqrt(s);++i) {
		if(s%i==0) {
			i=s/i;
			for(int j=1;j<=n;++j) {
				r[j]=a[j]%i;
			}
			sort(r+1,r+n+1);
			for(int j=1;j<=n;++j) sum[j]=sum[j-1]+r[j];
			int f=0;
			for(int j=1;j<=n;++j)
				if((n-j)*i-sum[n]==0&&sum[j]<=k) f=1;
			if(f) ans=max(ans,i);
			i=s/i;
			for(int j=1;j<=n;++j) {
				r[j]=a[j]%i;
			}
			sort(r+1,r+n+1);
			for(int j=1;j<=n;++j) sum[j]=sum[j-1]+r[j];
			f=0;
			for(int j=1;j<=n;++j)
				if((n-j)*i-sum[n]==0&&sum[j]<=k) f=1;
			if(f) ans=max(ans,i);
		}
	}
	printf("%d",ans);
}