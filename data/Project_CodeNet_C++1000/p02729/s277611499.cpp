#include <stdio.h>
 
int main()
{
	int N,M,a,b,total;
    scanf("%d %d",&N,&M);
 
    a= (N-1)*N/2;
    b= (M-1)*M/2;
    total= a + b;
 
    printf("%d",total);
 
    return 0;

}