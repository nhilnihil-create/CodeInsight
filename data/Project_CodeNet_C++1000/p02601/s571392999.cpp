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

int main()
{
    int a=read(),b=read(),c=read(),k=read();
    int tot=0;
    while(b<=a) b<<=1,tot++;
    while(c<=b) c<<=1,tot++;
    puts(tot<=k?"Yes":"No");

    return 0;
}
