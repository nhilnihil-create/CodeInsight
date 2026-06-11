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

#ifdef CURIOUSCAT
#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)
#else
#define Pr(f,...)
#endif

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=1e6+50,P=998244353;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int gcd(int a,int b){ return !b?a:gcd(b,a%b); }

int C(int n,int m) { 
	if (m<0||m>n)return 0;
	if(m<=1)return m==1?n:1;
	return 1ll*C(n/2,m/2)*C(n%2,m%2)%2;
}

int n,exist_1,ans1,ans2; 
char a[N];
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
#endif
	read(n); 
	scanf("%s", a+1); 
	rep(i,1,n){
		ans1^=(C(n-1,i-1)*((a[i]-'1')%2))%2;
		ans2^=C(n-1,i-1)*(a[i]=='3')%2;
		exist_1 |= a[i]=='2';
	}
	printf("%d\n",ans1?1:(exist_1?0:ans2*2)); 
	return 0;
}
