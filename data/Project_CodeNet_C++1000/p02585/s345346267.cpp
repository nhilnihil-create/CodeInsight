#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#include <cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef std::vector<int> VI;
typedef std::pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

const int maxn=5005;
int n,k,p[maxn],c[maxn];
LL ans=1e-15;

int main()
{
    n=read(),k=read();
    REP(i,1,n) p[i]=read();
    REP(i,1,n) c[i]=read();
    REP(i,1,n)
    {
        int cur=i,be=i;
        VI s;
        s.pb(cur);
        LL y=c[cur];
        cur=p[cur];
        while(cur!=be)
        {
            s.pb(cur);
            y+=c[cur];
            cur=p[cur];
        }
        LL t=0;
        for(int i=0;i<s.size();i++)
        {
            t+=c[s[i]];
            if(i>=k) break;
            LL temp=t;
            if(y>0) temp+=(k-i-1)/s.size()*y;
            ans=max(ans,temp);
        }
    }
    if(ans==0) cout<<*max_element(c+1,c+n+1);
    else cout<<ans;
    //cout<<ans;

    return 0;
}
