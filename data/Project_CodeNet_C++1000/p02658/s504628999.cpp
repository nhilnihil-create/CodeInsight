#include <stdio.h>

int main (){

	int n;
	scanf("%d", &n);
	
	long long int a1[n];
	long long int a2 = 1;
	long long int max = 1000000000000000000;
	long long int tot;
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &a1[i]);	
	}
	for(int u = 0; u < n; u++){
		if(a1[u] == 0){
			printf("0 \n");
			return 0;
		}
	}
	for(int y = 0; y < n ; y++){
        if(a1[y]<=max/a2){    
        a2*= a1[y];    
        }	else{
        	printf("-1\n");
        	return 0;
        }
    }
	printf("%lld\n", a2);
	
	return 0;
}