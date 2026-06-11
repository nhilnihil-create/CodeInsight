#include<stdio.h>
int main(void)
{
	int a,b,i,j,k;
	for(k=0;k<300;k++){
		scanf("%d %d",&a,&b);
		if(a==0&&b==0){
			break;
		}else{
			for(i=0;i<a;i++){
				if(i==0||i==a-1){
					for(j=0;j<b;j++){
						printf("#");
					}
				}else{
					for(j=0;j<b;j++){
						if(j==0||j==b-1){
							printf("#");
						}else{
							printf(".");
						}
					}
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}