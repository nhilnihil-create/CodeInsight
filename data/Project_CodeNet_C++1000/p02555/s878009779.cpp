#include <bits/stdc++.h>
int read(){
	int x=0,f=1;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	return x*f;
}
using Int = signed long long int;
const Int mod=Int(1e9)+7LL;
const int N=2000+10;

Int fix(Int x){ return (x%mod+mod)%mod; }
Int qpow(Int a,Int p=mod-2){
	a=fix(a); Int r=1; while(p){
		if(p&1) r=r*a%mod;
		a=a*a%mod; p>>=1;
	} return r;
}

int lim;
struct Poly{
	Int a[N];
	Poly(){ memset(a,0,sizeof(a)); }
	Int operator[](int x)const{return a[x];}
	Int& operator[](int x){return a[x];}
};
Poly operator*(const Poly&a,const Poly&b){
	Poly c;
	for(int i=0;i<=lim;i++) for(int j=0;j<=i;j++) c[i]=(c[i]+a[j]*b[i-j]%mod)%mod;
	return c;
}
Poly inv(const Poly &p){
	Poly q; q[0]=qpow(p[0],mod-2);
	for(int i=1;i<=lim;i++){
		Int tmp=0;
		for(int j=1;j<=lim;j++) tmp=(tmp+p[j]*q[i-j]%mod)%mod;
		// tmp+p[0]*q[i] = 0
		q[i]=fix(-tmp*q[0]%mod);
	}
	return q;
}



int main(){
	int n=read(); ::lim=2000;
	Poly up; up[0]=1; up[1]=fix(-1);
	Poly down; down[0]=1; down[1]=down[3]=fix(-1);

	Poly poly = up*inv(down);
	
	std::cout<<poly[n]<<std::endl;
	return 0;
}
// OGF: F(x)=(1-x)/(1-x-x^3)