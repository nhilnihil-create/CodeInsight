#include<stdio.h>

int main(){
	int h, a;
	scanf("%d %d", &h, &a);
	int check=0;
	check=h-a;
	if(check<0){
		printf("1\n");
	}
	else{
		if(h%a==0){
			printf("%d\n", h/a);
		}
		else{
			printf("%d\n", h/a+1);
		}
	}
	
	return 0;
}