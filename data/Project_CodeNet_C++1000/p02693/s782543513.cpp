#include<stdio.h>

int main(){
	int n, a, b;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	int flag=0;
	for(int i=a; i<=b; i++){
		if(i%n==0){
			printf("OK\n");
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("NG\n");
	}
	return 0;
}