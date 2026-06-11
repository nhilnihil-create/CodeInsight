#include <stdio.h>
long long x;//1<=a,b<=120
main(){
    scanf("%lld",&x);
    for(long long a=-118;a<=119;++a) for(long long b=-119;b<=118;++b) if(a*a*a*a*a-b*b*b*b*b==x) return printf("%lld %lld\n",a,b),0;
}