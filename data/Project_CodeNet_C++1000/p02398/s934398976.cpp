#include <stdio.h>
#include <iostream>

main()
{
int a,b,c,ans=0;
scanf("%d %d %d",&a,&b,&c);
for(int i=a;i<=b;i++){
	if(c%i==0)ans++;
}
printf("%d\n",ans);
}
