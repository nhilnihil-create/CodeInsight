//This program is written by Brian Peng.
#pragma GCC optimize("Ofast","inline","no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define Rd(a) (a=read())
#define Gc(a) (a=getchar())
#define Pc(a) putchar(a)
int read(){
	int x;char c(getchar());bool k;
	while(!isdigit(c)&&c^'-')if(Gc(c)==EOF)exit(0);
	if(c^'-')k=1,x=c&15;else k=x=0;
	while(isdigit(Gc(c)))x=(x<<1)+(x<<3)+(c&15);
	return k?x:-x;
}
void wr(int a){
	if(a<0)Pc('-'),a=-a;
	if(a<=9)Pc(a|'0');
	else wr(a/10),Pc((a%10)|'0');
}
signed const INF(0x3f3f3f3f),NINF(0xc3c3c3c3);
long long const LINF(0x3f3f3f3f3f3f3f3fLL),LNINF(0xc3c3c3c3c3c3c3c3LL);
#define Ps Pc(' ')
#define Pe Pc('\n')
#define Frn0(i,a,b) for(int i(a);i<(b);++i)
#define Frn1(i,a,b) for(int i(a);i<=(b);++i)
#define Frn_(i,a,b) for(int i(a);i>=(b);--i)
#define Mst(a,b) memset(a,b,sizeof(a))
#define File(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout)
#define N (510)
int n,k,a[N],s,f(1);
void slv(int x);
vector<int>v;
signed main(){
	Rd(n),Rd(k);
	Frn1(i,1,n)s+=Rd(a[i]);
	for(;f*f<=s;++f)if(!(s%f))slv(s/f);
	for(;f;--f)if(!(s%f))slv(f);
	exit(0);
}
void slv(int x){
	v.clear();
	Frn1(i,1,n)if(a[i]%x)v.push_back(a[i]%x);
	sort(v.begin(),v.end());
	int i(0),sv(0);
	for(;sv<=k&&i<v.size();++i)sv+=v[i];
	for(--i,sv=0;i<v.size();++i)if((sv+=x-v[i])>k)return;
	wr(x),exit(0);
}