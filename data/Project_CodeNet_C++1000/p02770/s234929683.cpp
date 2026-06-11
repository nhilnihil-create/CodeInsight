#include<bits/stdc++.h>
#define int __int128
using namespace std;
template<typename T>
inline void read(T &x)
{
	x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
}
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	x*=f;
	return;
}	
template<typename T>
void write(T x)
{
	if(x>=10) write(x/(__int128)10);
	putchar((int)(x%10)+'0');
	return;
}
const int MAXN=5010;
int k,q;
int a[MAXN];
int b[MAXN];
int s[MAXN];
signed main()
{
    read(k),read(q);
    for(int i=1;i<=k;i++) read(a[i]);
    for(int i=1;i<=q;i++)
    {
        int n,x,m;
        int cnt=0;
        read(n),read(x),read(m);
        for(int j=1;j<=k;j++)
        {
            b[j]=a[j]%m;
            if(b[j]==0) cnt++;
        }
        n--;
        for(int j=1;j<=k;j++) s[j]=s[j-1]+b[j];
        x%=m;
        x+=s[k]*(n/k);
        x+=s[n%k];
        cnt*=(n/k);
        for(int j=1;j<=n%k;j++)
        if(b[j]==0) cnt++;
        write(n-x/m-cnt),putchar('\n');
    }
	return 0;
}
