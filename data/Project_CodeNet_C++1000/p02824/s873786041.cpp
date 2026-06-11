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

const int N=1e5+50,P=1e9+7;
int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int gcd(int a,int b){ return !b?a:gcd(b,a%b); }
 
int n,m,v,p,a[N];
bool chk(int pos){
	if(a[pos]+m<a[p])return false;
	ll sum=1ll*(p-1+n-pos)*m;
	dec(i,pos-1,p)sum+=a[pos]+m-a[i];
	return sum>=1ll*m*(v-1);
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
#endif
	read(n),read(m),read(v),read(p); 
	rep(i,1,n)read(a[i]); 
	sort(a+1,a+n+1); 
	reverse(a+1,a+n+1); 
	int l=p,r=n+1; 
	while(r-l>1){
		int mid=(l+r)>>1; 
		if(chk(mid))l=mid;else r=mid;
	}
	printf("%d\n",l); 
	return 0;
}
