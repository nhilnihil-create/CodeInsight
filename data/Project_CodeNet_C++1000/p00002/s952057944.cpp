#include <stdio.h>
#include <stdlib.h>


int main(void){
	int a,b,x;
	while(scanf("%d %d",&a,&b)!=EOF){
		x=a+b;
		if(x/1000000){
			printf("7\n");
		} else if (x/100000!=0){
			printf("6\n");
		} else if (x/10000!=0){
			printf("5\n");
		} else if (x/1000!=0){
			printf("4\n");
		} else if (x/100!=0){
			printf("3\n");
		} else if (x/10!=0){
			printf("2\n");
		} else {
			printf("1\n");
		}
	}
}