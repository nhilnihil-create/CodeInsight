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

const int N=1e5+5;
int n,m,v,p,a[N],ans,sum;

signed main(){
	read(n,m,v,p);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n,greater<int>());
	ans=p;sum=a[p];
	for(int i=p+1;i<=n;i++){
		if(a[i]+m>=a[p]&&(a[i]+m)*(i-p)-sum>=m*(v-n+i-p)) ans++;
		else break;
		sum+=a[i];
	}
	write(ans);
}