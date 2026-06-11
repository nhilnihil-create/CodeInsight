#include<cstdio>
main(){for(int a,b;~scanf("%d%d",&a,&b);printf("%d\n",++b))for(a+=b,b=0;a/10;b++,a/=10);}