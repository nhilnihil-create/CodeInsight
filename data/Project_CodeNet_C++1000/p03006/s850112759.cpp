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
#define pii pair<int,int>
#define x first
#define y second

const int N=55;
map<pii,int> cnt;
pii a[N];
int n,ma;

signed main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i].x,a[i].y);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ma=max(ma,++cnt[pii(a[j].x-a[i].x,a[j].y-a[i].y)]);
	write(n-ma);
}