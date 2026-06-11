#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=200005;
ll tot;
int n,a[N],b[N];
void GG(){
	puts("-1"); exit(0);
}
bool check(){
	For(i,0,n-1)if(a[i]!=b[i])return 0;
	return 1;
}
int main(){
	n=read();
	For(i,0,n-1)a[i]=read();
	For(i,0,n-1)b[i]=read();
	while(!check()){
		For(i,0,n-1)if(a[i]!=b[i]&&b[i]>b[(i+1)%n]&&b[i]>b[(i+n-1)%n]){
			if(a[i]>b[i])GG();
			int x=b[(i+1)%n]+b[(i+n-1)%n],ls=b[i];
			b[i]=max(b[i]%x,a[i]+(b[i]-a[i])%x);
			if(b[i]==ls)GG();
			else tot+=(ls-b[i])/x;
		}
	}
	cout<<tot<<endl;
}
/*
RGRBGB

*/