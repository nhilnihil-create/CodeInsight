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

const int N=2e5+5;
int a[N],m,cnt[N],n,b[5];

void GG(){
	puts("No");
	exit(0);
}

void OK(){
	puts("Yes");
	exit(0);
}

signed main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	a[0]=-1;
	for(int i=1;i<=n;i++) a[i]==a[i-1]?cnt[m]++:cnt[++m]++;
	if(m>3) GG();
	m=0;for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) b[++m]=a[i];
	if(m==1&&!b[1]) OK();
	if(n%3) GG();
	if(m==2&&!b[1]&&cnt[1]==n/3) OK();
	if(m<3) GG();
	if(cnt[1]!=n/3||cnt[2]!=n/3||cnt[3]!=n/3) GG();
//	printf("#%d %d %d %d %d %d\n",b[1],b[2],b[3],b[1]^b[2],b[2]^b[3],b[1]^b[3]);
	if((b[1]^b[2])==b[3]) OK();
	if((b[1]^b[3])==b[2]) OK();
	if((b[2]^b[3])==b[1]) OK();
	GG();
}