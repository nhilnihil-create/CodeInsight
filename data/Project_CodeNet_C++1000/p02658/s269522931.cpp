#include <stdio.h>
int main (){
    long long int n; 
    long long int t=1;//biar kalo dikali ga 0 dan dibagi ga 0;
    
    scanf("%lld",&n);
    long long int A[n]; 
    
    for(int i=0; i<n; i++){
        scanf("%lld", &A[i]);
    }
    
    for(int j=0; j<n; j++){
        if(A[j] == 0){  
            printf("0");
            return 0;
        }
    }
    
    for(int k=0; k<n; k++){
        if(A[k] <= 1000000000000000000/t){
            t = t*A[k];
        } 
		else {
            printf("-1");
            return 0;
        }
    }
    
    printf("%lld", t);
    
    
return 0;
}