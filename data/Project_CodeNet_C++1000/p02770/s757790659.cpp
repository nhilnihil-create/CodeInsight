#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	x=0;char c=getchar();bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return  x;
}
template<class t> inline void write(t x){
	if(x<0){putchar('-'),write(-x);}
	else{if(x>9)write(x/10);putchar('0'+x%10);}
}

#define int long long

const int N=5e3+5;
int k,q,a[N],pre[N],zero[N];

void doit(){
	int n,x,m;
	read(n);read(x);read(m);
	for(int i=1;i<=k;i++) pre[i]=pre[i-1]+a[i]%m;
	int y=x+pre[k]*((n-1)/k)+pre[(n-1)%k];
	for(int i=1;i<=k;i++) zero[i]=zero[i-1]+(a[i]%m==0);
	write((n-1)-((y/m-x/m)+(zero[k]*((n-1)/k)+zero[(n-1)%k])));puts("");
}

signed main(){
	read(k);read(q);
	for(int i=1;i<=k;i++) read(a[i]);
	while(q--) doit();
}