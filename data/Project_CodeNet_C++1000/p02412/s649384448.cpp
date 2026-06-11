#include<stdio.h>
main(){
	int n,x;
	int i,j,k;
	int num;
	int sum;

	while(1){
		num = 0;
		scanf("%d %d",&n,&x);
		if(n == 0 && x == 0) break;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=j+1;k<=n;k++){
					sum = i+j+k;
					if(sum == x){
						num++;
						// printf("%d %d %d\n",i,j,k);
					}
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}