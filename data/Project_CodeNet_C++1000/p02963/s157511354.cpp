#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define int long long

const int A=1e9,B=1e18;
int S,x=1e9,xx=1,y,yy;

signed main(){
	read(S);
	yy=S/x;
	if(x*yy<S) yy++;
	y=x*yy-S;
	printf("0 0 %lld %lld %lld %lld\n",x,y,xx,yy);
}