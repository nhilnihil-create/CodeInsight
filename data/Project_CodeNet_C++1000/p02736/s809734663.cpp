#include<bits/stdc++.h>
using namespace std;
#define MN 1000005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
int C(int n,int m){return (n&m)==m;}
char ch[MN];
int n,a[MN];
int main(){
	scanf("%d%s",&n,ch+1);
	n--;
	bool op=0;
	for(int i=1;i<=n;++i)a[i]=abs(ch[i+1]-ch[i]),op|=(a[i]==1);
	if(!op)for(int i=1;i<=n;++i)a[i]>>=1;
	int ans=0;
	for(int j=1;j<=n;++j)ans^=C(n-1,j-1)*(a[j]&1);
	if(op)printf("%d\n",ans);
	else printf("%d\n",ans*2);
	return 0;
}















