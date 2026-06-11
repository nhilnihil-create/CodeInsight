#include <stdio.h>

int main(){

    long long int n, k;
    scanf("%lld %lld", &n, &k);
    long long int arrInput[n];
    for(int i=0;i<n;i++){
        scanf("%lld", &arrInput[i]);
    }
    for(int j=0;j<(n-k);j++){
        if(arrInput[j]>=arrInput[j+k]){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }

    return 0;
}