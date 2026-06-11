#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;

int main()
{
    ll x,k,d;
    scanf("%lld%lld%lld",&x,&k,&d);
    x=abs(x);
    ll tmp=min(x/d,k);
    k-=tmp;
    x-=tmp*d;
    if(k%2)
    {
        x=d-x;
    }
    printf("%lld",x);

}
