#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,tot,s[N];
ll a[N],sum,p[60];
void add(ll x)
{
    for(int i=0;i<tot;i++)
        if(1ll<<s[i]&x)
    {
        if(p[i]) x^=p[i];
        else {p[i]=x;break;}
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum^=a[i];
    for(int i=59;i>=0;i--) if(!(1ll<<i&sum)) s[tot++]=i;
    for(int i=1;i<=n;i++) add(a[i]);
    ll ans=0;
    for(int i=0;i<tot;i++)
        if(!(1ll<<s[i]&ans)) ans^=p[i];
    printf("%lld\n",ans+(sum^ans));
}
