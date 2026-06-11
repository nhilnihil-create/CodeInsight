#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N],l,f[N],n;
void up(int x){
	if (x==1)return;
	if (b[f[x]]>b[f[x/2]]){
		swap(f[x],f[x/2]);
		up(x/2);
	}
} 
void down(int x){
	int i=x;
	if (x*2<=l&&b[f[x]]<b[f[x*2]])i=x*2;
	if (x*2<l&&b[f[i]]<b[f[x*2+1]])i=x*2+1;
	if (i!=x){
		swap(f[x],f[i]);
		down(i);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]),f[i]=i;
	for (int i=1;i<=n;i++)
		if (b[i]<a[i]){
			puts("-1");
			return 0;
		}
	l=n;
	for (int i=n;i;i--)down(i);
	long long ans=0;
	while (l){
		int k=f[1];
		if (b[k]==a[k]){
			f[1]=f[l--];
			down(1);
			continue; 
		}
		int num=b[k==1?n:k-1]+b[k==n?1:k+1];
		int p=(b[k]-a[k])/num;
		if (!p){
			puts("-1");
			return 0;
		}
		b[k]-=p*num;down(1);
		ans+=p;
	} 
	printf("%lld\n",ans);
}