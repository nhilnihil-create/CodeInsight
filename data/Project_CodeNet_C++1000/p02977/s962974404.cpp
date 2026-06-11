#include<bits/stdc++.h>
#define Fail puts("NO"),exit(0);
#define eps 1e-10
#define maxn 200010
#define maxm 100010
#define inf 999999999999999
#define mod 998244353
#define pi acos(-1)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef bitset<maxn> bit;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int main()
{
    n=read();m=log2(n);
    if((1<<m)==n)   return puts("No"),0;
    puts("Yes");
    printf("%d %d\n",1,2);
    printf("%d %d\n",2,3);
    printf("%d %d\n",3,n+1);
    printf("%d %d\n",n+1,n+2);
    printf("%d %d\n",n+2,n+3);
    for(int i=2;2*i+1<=n;i++)
    {
        printf("%d %d\n",1,2*i);
        printf("%d %d\n",1,2*i+1);
        printf("%d %d\n",2*i,2*i+n+1);
        printf("%d %d\n",2*i+1,2*i+n);
    }
    if(!(n&1))
    {
        for(int i=2;i<=n;i++)
        {
            if(i==3)  continue;
            int y=(i^1^n);
            if(y==3||y>n)  continue;
            printf("%d %d\n",n,i);
            printf("%d %d\n",2*n,y);
            break;
        } 
    }
    return 0;
}