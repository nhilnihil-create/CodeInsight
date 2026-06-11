#include <stdio.h>

int main(){
int A, K, B, flag=0 ;
scanf("%d %d %d", &K, &A, &B);
for(int i=A; i<=B; i++)if(i%K==0) flag=1;
if(flag==1)printf("OK\n");
else printf("NG\n");
return 0;
}