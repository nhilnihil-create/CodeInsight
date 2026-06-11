#include<bits/stdc++.h>
using namespace std ;

int main()
{
    long long X , K , D ;
    scanf("%lld%lld%lld",&X,&K,&D) ;
    X = abs(X) ;
    long long p = X/D ;
    if(K<=p) printf("%lld\n",X-K*D) ;
    else
    {
        K -= p ;
        if(K%2) printf("%lld\n",abs(X-(p+1)*D)) ;
        else printf("%lld\n",X-p*D) ;
    }
    return 0 ;
}
