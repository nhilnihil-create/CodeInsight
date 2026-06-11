#include <stdio.h>

int main(){
    
    int k, a, b;
    scanf("%d", &k);
    scanf("%d %d", &a, &b);
    
    for(int i = 1 ; i < 1000 ; i++){
    	int temp = k;
    	temp*=i;
		// printf("Temp number: %d\n", temp);
		if(temp >= a && temp <= b){
    		printf("OK\n");
    		// printf("%d\n", i);
			break;
		}
		else if(temp > b){
			printf("NG\n");
			// printf("%d\n", i);
			break;
		}
	}
    
	
	return 0;
}

