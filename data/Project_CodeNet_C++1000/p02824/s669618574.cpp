#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define For(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
inline ll read(){
	ll x=0;char ch=getchar();bool f=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return f?-x:x;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);putchar(x%10+'0');
}
void writeln(ll x){write(x);puts("");}
void writep(ll x){write(x);putchar(' ');}

int const N=1e5+3;
int n,m,kk,p,ans,sum,b[N],a[N];

bool cmp(int x,int y){
	return x>y;
}
signed main(){
	n=read();m=read();kk=read();ans=p=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for (int i=1;i<p;i++) sum+=a[i];
	int k=1;
	for (int i=p+1;i<=n;i++){
		while (a[i]+m<a[k]) sum-=a[k],k++;
		if (k>p) break;
		if ((a[i]+m)*(i-k)-(b[i-1]-b[k-1])+(n-i+k-1)*m+sum-a[i]*(p-k)>=(kk-1)*m) ans++;
	}
	writeln(ans);
	return 0;
}