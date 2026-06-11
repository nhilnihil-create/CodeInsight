#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const int N=1e5+5;
const ll mod=998244353;
int d[N],cnt[N];
int main(){
	int n=read();
	for(int i=1;i<=n;++i)
		d[i]=read();
	if(d[1]!=0) return puts("0"),0;
	for(int i=1;i<=n;++i)
		cnt[d[i]]++;
	int ans=1;
	for(int i=2;i<=n;++i)
		ans=1ll*ans*cnt[d[i]-1]%mod;
	cout<<ans;
	return 0;
}
