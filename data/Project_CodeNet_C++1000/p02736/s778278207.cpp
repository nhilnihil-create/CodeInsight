#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
char s[N];
int n,a[N];
ll f(int x)
{
    ll ans=0;
    while(x)
    {
        x/=2;ans+=x;
    }
    return ans;
}
ll C(int n,int m)
{
    return f(n)-f(n-m)-f(m);
}
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++) a[i]=s[i]-'0'-1;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]&1)
        if(C(n-1,i-1)==0) ans^=1;
    if(ans) printf("1\n");
    else
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) {printf("0\n");return 0;}
            if(a[i]==2&&C(n-1,i-1)==0) ans^=1;
        }
        if(ans) printf("2\n");
        else printf("0\n");
    }
}
