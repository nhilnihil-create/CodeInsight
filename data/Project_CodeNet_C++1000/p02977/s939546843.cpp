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
#define fore(i,v) for(int i=G[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
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

/*
const int N=,P=;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int gcd(int a,int b){ return !b?a:gcd(b,a%b); }
*/


const int N = 3e5 + 50, L = 20; 

int n,p[N];

void e(int u, int v) { printf("%d %d\n", u, v); } 

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	freopen("d.in", "r", stdin); 
#endif
	read(n); 
	int t = 1; for (;t <n;t *= 2); 
	if (n != t&&n!=1&&n!=2) {
		puts("Yes"); 
		e(1,2),e(2,3),e(3,n+1),e(n+1,n+2),e(n+2,n+3);
		p[1]=n+1,p[2]=n+2,p[3]=3;
		if (n & 1) {
			for(int i=4;i<=n;i+=2){
				e(i,i+1),e(n+i,n+i+1),e(i,n+1),e(n+1,n+i+1);
				p[i]=i,p[i+1]=n+i+1;
			}
		}else{
			for(int i=4;i+1<=n;i+=2){
				e(i,i+1),e(n+i,n+i+1),e(i,n+1),e(n+1,n+i+1);
				p[i]=i,p[i+1]=n+i+1;
			}
			rep(i,2,n-1){
				if(2<=(n^i^1)&&(n^i^1)<=n-1){
				//	Pr("z=%d,%d\n",n^i^1,i);
					e(n,p[i]),e(p[n^i^1],n+n);
					return 0; 
				}
			}
		}
	}else puts("No"); 
	return 0; 
}
