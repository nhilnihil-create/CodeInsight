#include <stdio.h>

int main(){
	int a,b,c;	
	scanf("%d", &a);
	scanf("%d %d", &b, &c);
	
	for(int i = b; i<=c; i++){
		
		if (i%a == 0){
			printf("OK\n");
			return 0;
		}	
	}
	
	printf("NG\n");
	
return 0;
}