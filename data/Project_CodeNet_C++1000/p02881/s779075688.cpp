#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i;
    scanf("%lld",&n);
    double f=sqrt(n);
    i=f+1;
    for(;i>=1;i--){
        if(n%i==0){
            break;
        }
    }
    printf("%lld\n",i+n/i-2);

    return 0;
}
