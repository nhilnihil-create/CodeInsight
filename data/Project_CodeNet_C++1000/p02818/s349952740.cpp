///c. greedy takahashi
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    long long int a,b,k;
    scanf("%lld%lld%lld",&a,&b,&k);
    if(k>=a){
        k=k-a;
        a=0;
    }
    else{
        a=a-k;
        k=0;
    }
    if(k>=b) b=0;
    else b=b-k;

    printf("%lld %lld",a,b);
    return 0;
}