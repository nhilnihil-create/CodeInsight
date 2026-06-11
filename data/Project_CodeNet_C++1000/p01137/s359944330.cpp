#include<cstdio>
#include <string>
main(){int e;while(scanf("%d",&e)&&e){int m=1<<30;for(int z=0,c=0;c<=e;c=++z*z*z)for(int y=0,b=0;c+b<=e;b=++y*y)m=std::min(m,e-c-b+y+z);printf("%d\n",m);}}