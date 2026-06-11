#include<stdio.h>
int main()
{
	int n,k,d,a,i,j,c=0,f[101]={0};
	scanf("%d %d",&n,&k);
	for(i=0;i<k;i++){
		scanf("%d",&d);
		for(j=0;j<d;j++){
			scanf("%d",&a);
			f[a]=1;
		}
	}
	for(i=1;i<=n;i++){
		if(f[i]==0) c++;
	}
	printf("%d\n",c);
	return 0;
}
