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
    int x=read();
    if(x<600) putchar('8');
    else if(x<800) putchar('7');
    else if(x<1000) putchar('6');
    else if(x<1200) putchar('5');
    else if(x<1400) putchar('4');
    else if(x<1600) putchar('3');
    else if(x<1800) putchar('2');
    else if(x<2000) putchar('1');

    return 0;
}
