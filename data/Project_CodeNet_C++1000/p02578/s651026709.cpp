#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
const int N=1e6+10;
void read(int &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
void read(ll &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
int a[N];
int main()
{
    int n;read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    ll ans=0;
    for(int i=2;i<=n;i++) if(a[i]<a[i-1]) ans+=a[i-1]-a[i],a[i]+=a[i-1]-a[i];
    printf("%lld\n",ans);
    return 0;
}
