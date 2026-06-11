#include <stdio.h>

int main(){
int N;
scanf("%d",&N);
(N % 2 == 0)? printf ("%d\n",(N/2)) : printf ("%d\n", (N/2)+1);
return 0;
}