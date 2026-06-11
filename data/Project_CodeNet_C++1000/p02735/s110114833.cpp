#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=105,P=1e9+7;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int gcd(int a,int b){ return !b?a:gcd(b,a%b); }

int n, f[N][N], m; 
char g[N][N]; 

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	freopen("d.in", "r", stdin); 
#endif
	read(n), read(m); 
	rep(i, 1, n) scanf("%s", g[i]+1); 
	mem(f, 0x3f); 
	f[0][1] = f[1][0] = 0; 
	g[0][1] = g[1][0] = '&';
	rep(i, 1, n) rep(j, 1, m) {
		if (g[i][j] == '.') {
			f[i][j] = min(f[i-1][j],f[i][j-1]); 
		} else {
			f[i][j] = min(f[i-1][j]+(g[i-1][j]!='#'),f[i][j-1]+(g[i][j-1]!='#')); 
		}
	}
	printf("%d\n", f[n][m]); 
	return 0;
}
