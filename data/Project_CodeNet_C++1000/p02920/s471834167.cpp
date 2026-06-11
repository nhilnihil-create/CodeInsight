#include<bits/stdc++.h>
using namespace std;
#define next Next
#define last Last
const int N=1e6+5;
int n,a[N],b[N],s[N];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
	int ret=0,f=0;char c=gc();
	while(!isdigit(c)){if(c=='-')f=1;c=gc();}
	while(isdigit(c)){ret=ret*10+c-48;c=gc();}
	if(f)return -ret;return ret;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	n=read();
	for(int i=0;i<(1<<n);i++)a[i]=read();
	sort(a,a+(1<<n),cmp);
	b[0]=1;s[0]=a[0];
	for(int i=0;i<n;i++)
	{
		int size=1<<i,k=0;
		for(int j=0;j<(1<<n);j++)
			if(!b[j]&&k<size&&a[j]<s[k])
			{
				s[size+k]=a[j];
				b[j]=1;
				k++;
			}
		if(k<size){puts("No");return 0;}
		sort(s,s+(size<<1),cmp);
	}
	puts("Yes");
}