#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n;
int ans;

int main()
{
    scanf("%lld",&n);
    if(n==2) return printf("1"),0;
    ll i;
    for(i=1;i*i<=n-1;i++) if((n-1)%i==0)
        if(i==1||(n-1)/i==i) ans++; else ans+=2;
    for(i=2;i*i<=n;i++) if(n%i==0)
    {
        ll t=n;
        while(t%i==0) t/=i;
        if(t%i==1) ans++;
    }
    printf("%d",ans+1);
    return 0;
}