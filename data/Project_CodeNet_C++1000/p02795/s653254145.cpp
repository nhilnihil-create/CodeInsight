#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
    int x=0;bool f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=0;c=getchar();}
    while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?x:-x;
}
int h,w,n,m;
int main()
{
    h=read(),w=read(),n=read();
    m=max(h,w);
    printf("%d\n",(n+m-1)/m);
    return 0;
}
