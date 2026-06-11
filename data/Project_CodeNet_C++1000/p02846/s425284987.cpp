#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t1,t2,a1,a2,b1,b2;
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld",&t1,&t2,&a1,&a2,&b1,&b2);
    ll a=a1-b1,b=a2-b2;
    if(a<0) a*=-1,b*=-1;
    ll k=t1*a+t2*b;
    if(k==0) {printf("infinity\n");return 0;}
    if(k>0){printf("0\n");return 0;}
    ll ans=a*t1/(-k)*2+(b*t2%k!=0);
    printf("%lld\n",ans);
}
