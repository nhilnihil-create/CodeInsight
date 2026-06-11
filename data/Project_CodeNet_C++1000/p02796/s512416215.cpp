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

#define pii pair<int,int>
#define x first
#define y second

const int N=1e5+5;
pii a[N];
int n,ans;

bool cmp(pii x,pii y){
  return x.y<y.y;
}

signed main(){
	read(n);
	for(int i=1,x,y;i<=n;i++) read(x,y),a[i]=pii(x-y,x+y);
	sort(a+1,a+1+n,cmp);
	for(int i=1,ma=INT_MIN;i<=n;i++)
		if(a[i].x>=ma) ans++,ma=a[i].y;
	write(ans);
}