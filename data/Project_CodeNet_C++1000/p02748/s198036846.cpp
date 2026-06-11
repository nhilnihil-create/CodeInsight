#include <cstdio>
#include <algorithm>
using namespace std;

#define N 1000005

int ans=N;
int n1,n2,a[N],b[N],m;

inline int read(){
	int s=0,t=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),t=-1;
	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return s*t;
}

int main(void){
	n1=read();
	n2=read();
	m=read();
	for(int i=1;i<=n1;i++)
	a[i]=read();
	for(int i=1;i<=n2;i++)
	b[i]=read();
	for(int i=1;i<=n1;i++)
	ans=min(ans,a[i]); 
	int s=ans;
	ans=ans+b[1];
	for(int i=1;i<=n2;i++)
	ans=min(ans,s+b[i]);
	for(int i=1;i<=m;i++){
		int x,y,c;
		x=read();
		y=read();
		c=read();
		ans=min(ans,a[x]+b[y]-c);
	}
	printf("%d\n",ans);
}