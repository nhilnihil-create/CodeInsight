#include <stdio.h>
#include <iostream>

main()
{
int a,b;
   while(1){
   	scanf("%d %d",&a,&b);
   	if((a|b)==0)break;
   	if(b<a)std::swap(a,b);
   	printf("%d %d\n",a,b);
    }
}
