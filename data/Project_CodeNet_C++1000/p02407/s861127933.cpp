#include<stdio.h>
main(){
	int MAX_N = 100;
	int a[MAX_N];
	int n;
	int i;

	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[n-i]);
	}

	for(i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",a[i]);
	}

	printf("\n");
	return 0;
}