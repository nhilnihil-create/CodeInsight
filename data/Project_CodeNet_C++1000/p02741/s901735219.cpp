#include<cstdio>
using namespace std;
inline int read()
{
    int x=0;bool f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=0;c=getchar();}
    while(c>='0' && c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?x:-x;
}
int k;
int ans[]={1,1,1,2,1,2,1,5,2,2,1,5,1,2,1,14,1,5,1,5,2,2,1,15,2,2,5,4,1,4,1,51};
int main()
{
    k=read();
    printf("%d\n",ans[k-1]);
    return 0;
}
