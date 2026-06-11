#include <stdio.h>

int main(){

	int k, a, b;
	scanf("%d", &k);
	scanf("%d %d", &a, &b);
	int flag = 0;
	    
	for(int i=a; i<=b; i++){
		
		if ( i % k == 0){
		flag = 1;	
		break;
	
}
}
flag? printf("OK\n") : printf("NG\n");
	

	return 0;
}

