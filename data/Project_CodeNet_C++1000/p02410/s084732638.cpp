#include<stdio.h>
main(){
	int n,m;
	int MAX_N = 100;
	int MAX_M = 100;
	int a[MAX_N][MAX_M];
	int b[MAX_M];
	int c[MAX_N];
	int i,j;

	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}

	for(i=0;i<n;i++){
		c[i] = 0;
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c[i] = c[i] + a[i][j] * b[j];
		}
	}

	for(i=0;i<n;i++){
		printf("%d\n",c[i]);
	}
	return 0;
}