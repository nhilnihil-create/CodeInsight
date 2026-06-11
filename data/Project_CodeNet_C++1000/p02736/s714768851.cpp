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

const int N=1e6+5;
bool exists,a[N],b[N];
int n;

bool C(int n,int m){
	if(n<m) return 0;
	if(n<=1) return 1;
	return C(n&1,m&1)&C(n>>1,m>>1);
}

bool calc(bool *a){
	bool ans=0;
	for(int i=1;i<=n;i++) if(a[i]) ans^=C(n-1,i-1);
	return ans;
}

signed main(){
	read(n);
	for(int i=1,x;i<=n;i++){
		scanf("%1d",&x);x--;
		exists|=x==1;
		a[i]=x&1;
		b[i]=x>>1;
	}
	if(exists) write(calc(a));
	else write(calc(b)<<1);
}