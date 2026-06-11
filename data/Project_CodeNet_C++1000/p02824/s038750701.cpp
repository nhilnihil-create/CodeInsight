#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,k,p,sum;
int a[N],bin[N];

inline bool jay(int i)
{
	if (a[i]+m<a[p]) return false;
	int last=k-(n-i+1);
	if (last<p) return true;
	int hh=bin[i-1]-bin[p-1];
	hh=((i-1)-p+1)*(a[i]+m)-hh;
	if (hh>=(k-(n-i+1)-(p-1))*m) return true;
	else return false;
}	

//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    int ret=0,ff=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-ff;ch=getchar();}
    while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+ch-'0';ch=getchar();}
    return ret*ff;
}

signed main(){
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout); 
	n=read(); m=read(); k=read(); p=read();
	for (register int i=1; i<=n; ++i) a[i]=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (register int i=1; i<=n; ++i) bin[i]=bin[i-1]+a[i];
	int now=p+1;
	while (a[now]==a[p] && now<=n) 
	{
		now++; 
	}
	sum=now-1;
	
	int i=now;
	while (i<=n)
	{
		if (jay(i)) sum++;
		else break;
		int j=i+1;
		while (j<=n && a[j]==a[i]) sum++,j++;
		i=j; 
	}
	printf("%lld\n",sum);
return 0;
}