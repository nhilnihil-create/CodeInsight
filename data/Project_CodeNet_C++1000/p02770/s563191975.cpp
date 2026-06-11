#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<bitset>
#include<deque>
#define Fail puts("NO"),exit(0);
#define eps 1e-10
#define maxn 5050
#define maxm 100010
#define mod 1000000007
#define inf 1000000007
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>pii;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int K,Q;
int d[maxn];
int main()
{
    K=read();Q=read();
    for(int i=0;i<K;i++)  d[i]=read();
    while(Q--)
    {
        int n=read(),x=read(),m=read();x%=m;
        ll sum=0,cnt=0;
        for(int i=0;i<K;i++)  sum+=(d[i]%m),cnt+=(d[i]%m==0);
        ll add=1ll*((n-1)/K)*sum;cnt=cnt*((n-1)/K);
        for(int i=0;i<=n-2-((n-1)/K)*K;i++)  add+=(d[i]%m),cnt+=(d[i]%m==0);
        cout<<(n-1-(add+x)/m+x/m)-cnt<<endl;
    }
    return 0;
}
