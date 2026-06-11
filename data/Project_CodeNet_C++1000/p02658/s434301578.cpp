#include <stdio.h>

int main(){
    
    int kloadaNol = 0;
    int a;
    long long b, temp;
    long long ans = 1;
    scanf("%d", &a);

    long long arr[100000];
    for (int i=0; i<a; i++){
        scanf("%lld", &arr[i]);
        if (arr[i] == 0){
            kloadaNol = 1;
        }
    }
    
    if (kloadaNol == 0){
        for(int i = 0 ; i < a ; i++){
			if(arr[i]<=1000000000000000000/ans){
				ans*=arr[i];
			}
            else{
            	printf("-1\n");
            	return 0;
			}
        }
        printf("%lld\n", ans);
    }
    else{
    	printf("0\n");
	}
	
	return 0;
}