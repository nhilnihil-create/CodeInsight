#include<stdio.h>

int main(){
	int a;
	scanf("%d", &a);
	while (a>0){
		if (a%10==7){
			printf("Yes\n");
			break;
		} else{
			if (a<10){
				printf("No\n");
			}
		}
		a/=10;
	}
	return 0;
}