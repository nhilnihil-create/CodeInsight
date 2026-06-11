#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    int totalm=(m*(m-1))/2;
    int totaln=(n*(n-1))/2;
    printf("%d\n", totalm+totaln);


    return 0;
}