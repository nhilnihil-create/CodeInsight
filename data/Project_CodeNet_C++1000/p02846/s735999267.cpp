#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sint(a) scanf("%d",&a)
#define sint2(a,b) scanf("%d %d",&a,&b)
#define sll(a) scanf("%lld",&a)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define mem(a,i) memset(a,i,sizeof(a))
const double pi=acos(-1);
const int maxn=2e5+5;
const int mod=1e9+7;

int main()
{
    ll t1,t2;
    ll a1,a2,b1,b2;
    sll2(t1,t2);
    sll2(a1,a2);
    sll2(b1,b2);
    if(a1<b1&&a1*t1+a2*t2<b1*t1+b2*t2||a1>b1&&a1*t1+a2*t2>b1*t1+b2*t2)
          cout<<0<<endl;
    else if(a1*t1+a2*t2==b1*t1+b2*t2)
        cout<<"infinity"<<endl;
    else
    {
        if(a1<b1)
        {
            ll t=a1;
            a1=b1;
            b1=t;
            t=a2;
            a2=b2;
            b2=t;
        }
        ll s1=(a1-b1)*t1;
        ll s2=b1*t1+b2*t2-a1*t1-a2*t2;
        ll cj=s2;
        ll sum=0;
        if(s1%cj==0)
            sum+=2*(s1/cj);
        else
            sum+=2*(s1/cj)+1;
        printf("%lld\n",sum);
    }
    return 0;
}
/*120 157
339 381
555 213*/
