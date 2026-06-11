#define DIN freopen("input.txt","r",stdin);
#define DOUT freopen("output.txt","w",stdout);
#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define REP_(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> P;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}

LL n,a[100];

int main()
{
    n=read();
    REP(i,1,n) a[i]=read();
    LL m=1000;
    REP(i,2,n) if(a[i]>a[i-1]) m+=m/a[i-1]*(a[i]-a[i-1]);
    cout<<m;

    return 0;
}
