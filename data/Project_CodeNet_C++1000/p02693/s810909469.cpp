#include <stdio.h>
int main(){
    int K, A, B;
    scanf("%d", &K);
    scanf("%d %d", &A, &B);
    int L = B - A;
    int count = 0;
    for(int i = 0; i <= L ; i++){
        int total = A % K;
        A++;
        if(total == 0){
            count++;
        }
        else{
            count = count + 0;
    	}
	}
    
	if(count > 0){
        printf("OK\n");
    }
    else{
        printf("NG\n");
    }
	
 return 0;
}