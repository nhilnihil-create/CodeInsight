#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
int n;
int main() {
	read(n);rep(i,0,18)if((1<<i)==n){puts("No");return 0;}
	puts("Yes");
	for(int i=1;i*2+1<=n;i++){
		printf("%d %d\n",1,i*2);
		printf("%d %d\n",1,i*2+1);
		printf("%d %d\n",i*2,i*2+1+n);
		printf("%d %d\n",i*2+1,i*2+n);
	}
	printf("%d %d\n",1+n,2+n);
	if(n%2==0){
		int c=n^1;
		rep(i,2,n)if((c^i)<=n){
			printf("%d %d\n",n,i);
			printf("%d %d\n",n*2,c^i);
			break;
		}
	}
	return 0;
}
