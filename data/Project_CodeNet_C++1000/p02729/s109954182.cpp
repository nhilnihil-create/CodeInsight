#include <stdio.h>

int main(){

    int N,M,hasil;
    scanf("%d %d", &N, &M);
    
    hasil= N*(N-1)/2+M*(M-1)/2;
    printf("%d\n",hasil);
    
    return 0;
}