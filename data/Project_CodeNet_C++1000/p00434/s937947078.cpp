#include<stdio.h>
int main(void)
{
	int m[31],n[29],i,x[30],w=0,j;
	for(i=1;i<=28;i++) scanf("%d",&n[i]);
	for(i=1;i<=30;i++) x[i]=0;	
	for(i=1;i<=28-1;i++){
		for(j=i+1;j<=28;j++){
			if(n[i]>n[j]){
				w=n[i];
				n[i]=n[j];
				n[j]=w;
			}
		}
	}
	for(i=1;i<=28;i++) x[n[i]]=1;
	for(i=1;i<=30;i++){
		if(x[i]!=1){
			printf("%d\n",i);
		}
	}	
	return 0;
}