#include <stdio.h>

int main(){
    long long n;
    scanf("%lld", &n);
    long long a[n+1];
    long long hasil = 1;
    int flag = 1;
    int print;
    
    for(int i = 0; i<n; i++){
    	scanf("%lld", &a[i]);
    	if(a[i] == 0){
    		printf("0");
    		flag = 0;
    		break;
    	}
    }
    
    if(flag){
	    for(int i = 0; i<n; i++){
	    	if(a[i] > 1000000000000000000/hasil){
	    		flag = 0;
	        	break;
	    	}
	        hasil *= a[i]; 
	        if(i >= n-1){
	        	     print = 1;
	    }
    }
    
    if(print){
    	flag ? printf("%lld\n", hasil) : printf("-1\n");
    }
    
    return 0;
	}
}