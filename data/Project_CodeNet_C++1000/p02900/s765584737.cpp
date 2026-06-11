#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long prime(long long n){
    long long i;
    if(i==3||i==2)
        return 1;
    for(i=2;i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    long long a,b,i,tt=0,tnt=0,d;
    scanf("%lld%lld",&a,&b);
    long long c=__gcd(a,b);
    if(c==1){
        printf("1\n");
        return 0;
    }
    if(prime(c)==1)
        tt++;
    else{
            tt=0;
    for(i=2;i<=c;i++){
        if(c%i==0){
            //printf("1\n");
            tt++;
            d=c/i;
            c=d;
            while(c%i==0){
                d=c/i;
                c=d;}
                //printf("%lld\n",c);
            long long y=prime(c);
           if((y==1)&&c>1){
            tt++;
            //printf("haha %lld\n",tt);
            tnt=1;
           }

        }
        if(tnt==1)
        break;
    //printf("%lld\n",tot);

    }
    }
    tt++;

    printf("%lld\n",tt);

}
