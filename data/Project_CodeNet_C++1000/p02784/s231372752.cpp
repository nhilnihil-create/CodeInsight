#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+4;
int x,n,y;
inline int read() {
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void smax(int &x,int y) {
	x=x<y?y:x;
}
inline void smin(int &x,int y) {
	x=x>y?y:x;
}
int main() {
//	freopen("in.txt","r",stdin);
	x=read(),n=read();
	for (register int i=1;i<=n;++i) y+=read();
	puts(x<=y?"Yes":"No");
	return 0;
}