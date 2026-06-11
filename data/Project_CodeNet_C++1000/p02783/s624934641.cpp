#include<stdio.h>
int main(){
	int h;
	int a;
	int x;
	scanf("%d %d", &h, &a);
	if(a>h){
		printf("1");
	}
	else if(h>=a){
		x = (h-1)/a+1;
		printf("%d", x);
	}

	return 0; 
}