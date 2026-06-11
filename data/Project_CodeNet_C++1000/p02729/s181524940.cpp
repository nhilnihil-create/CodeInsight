#include<stdio.h>
int main()
{
    int N, M, hasil1,hasil2 ;
    scanf("%d %d", &N, &M);
    hasil1=(N-1)*(N)/2;
    hasil2=(M-1)*(M)/2;
    printf("%d", hasil1+hasil2);
return 0;
}