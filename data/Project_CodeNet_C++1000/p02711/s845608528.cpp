#include <stdio.h>

int main(){	
	int num;
	scanf("%d", &num);

	if(num/100==7){
		printf("Yes\n");
	} else if(num/10%10==7){
		printf("Yes\n");
	} else if(num%10==7){
		printf("Yes\n");
	} else{
		printf("No\n");
	}
	
	
	return 0;
}