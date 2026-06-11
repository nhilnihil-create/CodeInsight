#include <stdio.h>

main()
{
int i[2],temp;

while(1)
 {
 scanf("%d %d",&i[0],&i[1]);
 if((i[0] == 0) && (i[1] == 0)) break;
 if(i[0]>i[1])
   {
    temp=i[0];i[0]=i[1];i[1]=temp;
   }
 printf("%d %d\n",i[0],i[1]);
 }
}