#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
template <typename T>inline T read()
{
    register T sum=0;
    register char cc=getchar();
    int sym=1;
    while(cc!='-'&&(cc>'9'||cc<'0'))cc=getchar();
    if(cc=='-')sym=-1,cc=getchar();
    sum=sum*10+cc-'0';
    cc=getchar();
    while(cc>='0'&&cc<='9')sum=sum*10+cc-'0',cc=getchar();
    return sym*sum;
}
template <typename T>inline T read(T &a)
{
    a=read<T>();
    return a;
}
template <typename T,typename... Others> inline void read(T& a, Others&... b)
{
    a=read(a);
	read(b...);
}
int n,a[maxn];
char str[maxn];
int solve()
{
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]==1)
			ans^=((n-1)&(i-1))==i-1;
	if(ans==1)
		return 1;
	bool flg=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
			return 0;
		else
		{
			flg&=a[i]==0;
			a[i]>>=1;
		}
	}
	if(flg)
		return 0;
	return solve()<<1;
}
int main()
{
	read(n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
		a[i]=str[i]-'1';
	printf("%d\n",solve());
    return 0;
}
