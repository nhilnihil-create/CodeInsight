#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
typedef long long LL;

int read()
{
    int x=0,flag=1;
    char c=getchar ();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

typedef pair<LL,LL> P;
P a[105];
int n;

int main()
{
    //freopen("input.txt","r",stdin);
    n=read();
    REP(i,1,n)
    {
        int x=read(),y=read();
        a[i]=P(x,y);
    }
    sort(a+1,a+n+1,[&](P x,P y) {
         return atan2(x.second,x.first)<atan2(y.second,y.first);});
    LL ans=0;
    REP(i,1,n)
    {
        int j=i;
        LL x=0,y=0;
        REP(k,1,n)
        {
            x+=a[j].first;
            y+=a[j++].second;
            if(j>n) j=1;
            ans=max(ans,x*x+y*y);
        }
    }
    printf("%.12f",sqrt(ans));

	return 0;
}
