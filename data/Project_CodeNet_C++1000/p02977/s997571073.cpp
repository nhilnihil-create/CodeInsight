#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)
#define il inline
#define LL long long
using namespace std;
il int read() {
	int res = 0,f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -f; ch = getchar();}
	while (isdigit(ch)) {res = (res<<3)+(res<<1)+ch-'0'; ch = getchar();} return res*f;
}
namespace qiqi {
	int n; void main() {
		n = read(); if (n == (n&(-n))) {puts("No"); return;} puts("Yes"); printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",1+n,1+n,2+n,2+n,3+n);
		rep(i,2,(n-1)>>1) printf("1 %d\n1 %d\n%d %d\n%d %d\n",i<<1,i<<1|1,i<<1|1,(i<<1)+n,i<<1,(i<<1|1)+n);
		if (!(n&1)) {rep(i,2,n) if (i != 3) {int x = n^i^1; if (x != 3 && x < n) {printf("%d %d\n%d %d\n",n,i,n<<1,x); break;}}}
	}
}
int main() {qiqi::main(); return 0;}