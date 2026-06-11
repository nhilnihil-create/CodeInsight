#include <stdio.h>
int a[200010],sum;
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),sum^=a[i];
	for(i=1;i<=n;i++)printf("%d ",sum^a[i]);
	return 0;
}