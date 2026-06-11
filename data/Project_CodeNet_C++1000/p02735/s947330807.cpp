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

const int N=105;
int n,m,f[N][N];
char s[N][N];

signed main(){
	read(n,m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(i==1&&j==1) {f[i][j]=s[i][j]=='#';continue;}
		f[i][j]=1e9;
		if(i>1) f[i][j]=min(f[i][j],f[i-1][j]+(s[i][j]=='#'&&s[i-1][j]=='.'));
		if(j>1) f[i][j]=min(f[i][j],f[i][j-1]+(s[i][j]=='#'&&s[i][j-1]=='.'));
	}
//	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=m;j++) write(f[i][j]),putchar(' ');return 0;
	write(f[n][m]);
}