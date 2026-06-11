#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int m,a[N];
ll ans=0;
int top,s[N];
int solve()
{
    while(top>1)
    {
        ans++;
        s[top-1]+=s[top];
        if(s[top-1]<10) top--;
        else
        {
            s[top]=s[top-1]%10;
            s[top-1]=1;
        }
    }
    return s[1];
}
int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int d;
        ll c;
        scanf("%d%lld",&d,&c);
        while(c>1)
        {
            if(c&1) s[++top]=d,c--;
            if(d==9)
            {
                ans+=c;
                c/=2;
            }
            else if(d==8)
            {
                ans+=c;
                c/=2;
                d=7;
            }
            else if(d==7)
            {
                ans+=c;
                c/=2;
                d=5;
            }
            else if(d==6)
            {
                ans+=c;
                c/=2;
                d=3;
            }
            else if(d==5)
            {
                ans+=c;
                c/=2;
                d=1;
            }
            else if(d==4)
            {
                ans+=c/2;
                c/=2;
                d=8;
            }
            else if(d==3)
            {
                ans+=c/2;
                c/=2;
                d=6;
            }
            else if(d==2)
            {
                ans+=c/2;
                c/=2;
                d=4;
            }
            else if(d==1)
            {
                ans+=c/2;
                c/=2;
                d=2;
            }
            else if(d==0)
            {
                ans+=c/2;
                c/=2;
                d=0;
            }
        }
        if(c==1) s[++top]=d;
        a[i]=solve();
        top=0;
    }
    while(m>1)
    {
        ans++;
        a[m-1]+=a[m];
        if(a[m-1]<10) m--;
        else
        {
            a[m]=a[m-1]%10;
            a[m-1]=1;
        }
    }
    printf("%lld\n",ans);
}
