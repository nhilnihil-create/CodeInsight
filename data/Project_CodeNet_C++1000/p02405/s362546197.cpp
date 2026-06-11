#include <stdio.h>
int main(void)
{
char x[2] = {'#', '.'};
int W, H, i, j, n;

while(1) {

scanf("%d %d",&H,&W);

if(H == 0 && W == 0)
   break;


for(j = 0; H > j; j++){

i = j % 2;
n = 0;

while(W > n){
printf("%c", x[i % 2]);
n++;
i++;
}
printf("\n");
}
printf("\n");
}
return 0;
}