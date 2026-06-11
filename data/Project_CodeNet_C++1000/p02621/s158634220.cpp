#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    
    int hasil = 0;
    hasil = n + n*n + n*n*n;
    
    printf("%d", hasil);
    return 0;
}