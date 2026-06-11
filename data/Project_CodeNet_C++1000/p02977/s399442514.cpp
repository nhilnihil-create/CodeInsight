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
void GG(){
	puts("No"); exit(0);
}
void add(int x,int y){
	wri(x); writeln(y);
}
int main(){
	int n=read(),f=0;
	for(int i=n;i>1;i>>=1)if(i&1)f=1;
	if(!f)GG();
	else{
		puts("Yes");
		add(n+1,3);
		for(int i=2;i<n;i+=2){
			add(i,i+1);
			add(i,1);
			add(i+1+n,1);
			add(i+1+n,i+n);
		}
		if(n%2==0){
			int t=n+1;
			For(i,2,t-1)if((t^i)<n){
				add(n,(i&1)?i+n:i);
				add(2*n,((t^i)&1)?(t^i)+n:(t^i));
				return 0;
			}
			while(1);
		}
	}
}