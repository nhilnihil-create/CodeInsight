#include<stdio.h>
int main()
{
	int h,n,a[100000];
	int i,m=0;
	scanf("%d %d",&h,&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		m+=a[i];
	}
	if(h-m<=0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}