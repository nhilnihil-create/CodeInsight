#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500010],b[500010],cnt[500010];
int pd(int i,int x){
	int sum,mid,l=m-i+1,r=m,hh=m-i;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]<x)hh=mid,l=mid+1;
		 else r=mid-1;
	}
	sum=b[hh]-b[m-i];
	sum=(hh-m+i)*x-sum;
	return b[m-i]>=sum;
}
int main(){
	int i,x,l,r,mid,mx;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=1;i<=n;i++)if(cnt[i]){
		m++;
		a[m]=cnt[i];
	}
	sort(a+1,a+m+1);
	for(i=1;i<=m;i++)b[i]=b[i-1]+a[i];
	for(i=1;i<=n;i++){
		if(i>m){
			puts("0");
			continue;
		}
		mx=0;
		l=1;r=n/i;
		while(l<=r){
			mid=(l+r)/2;
			if(pd(i,mid))mx=mid,l=mid+1;
			 else r=mid-1;
		}
		printf("%d\n",mx);
	}
}