#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t1,t2,a1,a2,b1,b2;
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld",&t1,&t2,&a1,&a2,&b1,&b2);
    ll p=(a1-b1)*t1,q=(a2-b2)*t2;
    if(p>0) p*=-1,q*=-1;
    if(p+q<0){cout<<0;return 0;}
    if(p+q==0){cout<<"infinity";return 0;}
    ll k=-p/(p+q);
    k*=2;
    if(-p%(p+q)) k++;
    printf("%lld\n",k);
}
