#include <cstdio>

int n,a[1000001];
int main(){
	scanf("%d",&n);
	bool cando=0;
	for(int i=1;i<=n;i++)scanf("%1d",a+i),--a[i],cando|=(a[i]==1);
	for(int i=1;i<=n;i++)if(a[i]==2)a[i]=!cando;
	int ans=0;
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
	for(int i=1;i<=n;i++)if(((n-i)&(i-1))==0)ans^=a[i];
	printf("%d\n",ans?(cando?1:2):0);
}