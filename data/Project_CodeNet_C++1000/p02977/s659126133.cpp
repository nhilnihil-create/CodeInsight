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

int n;

signed main(){
	read(n);
	if(!(n&(n-1))) return puts("No"),0;
	puts("Yes");
	for (int i=2;i+1<=n;i+=2){
		printf("%d %d\n",1,i),printf("%d %d\n",i,i+1);
		printf("%d %d\n",1,n+i+1),printf("%d %d\n",n+i+1,n+i);
	}
	printf("%d %d\n",3,n+1);
	if (n%2==0){
		int p=0;
		for(int i=1;i<=20;i++) if(n>>i&1){p=i;break;}
		printf("%d %d\n",n,(1<<p)+1+n);
		printf("%d %d\n",2*n,(n^(1<<p)));
	}
}