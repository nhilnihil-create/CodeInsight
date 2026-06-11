#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
inline void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void pr1(int x){write(x),putchar(' ');}
inline void pr2(int x){write(x),puts("");}
int a[510][510];
inline void dfs(int l,int r,int k)
{
	if(l>=r)return ;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;i++)
	{
		for(int j=mid+1;j<=r;j++)a[i][j]=k;
	}dfs(l,mid,k+1),dfs(mid+1,r,k+1);
}
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n=read();
    dfs(1,n,1);
    for(int i=1;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)pr1(a[i][j]);
    	pr2(a[i][n]);
    }
    return 0;
}