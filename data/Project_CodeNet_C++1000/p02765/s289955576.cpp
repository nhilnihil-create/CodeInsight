#include<stdio.h>
int main(){
	int a,b;
	scanf("%d %d", &a, &b);
	if(a >= 10){
		printf("%d", b);
	}else {
		printf("%d",b + 100 * (10-a));
	}
	return 0;
}