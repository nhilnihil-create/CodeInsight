#include<stdio.h>
main(){long long n,i;scanf("%lld",&n);for(i=n;--n;)i*=n;printf("%lld\n",i);}