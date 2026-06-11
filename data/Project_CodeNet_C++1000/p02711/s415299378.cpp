#include <stdio.h>

int main(){
	int inp;
	scanf("%d", &inp);
	int a=inp/100, b=inp%100/10, c=inp%100%10;
	if(a==7 || b==7 || c==7){
		printf("Yes");
	}else{
		printf("No");
	}
	
	
	return 0;
}