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
 
#define Pr(f,...) //fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)
 
typedef long long ll;
 
template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}
 
const int N=2e5+50,P = 998244353;
 
 
int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int gcd(int a,int b){ return !b?a:gcd(b,a%b); }
void upd(int &a,int b){ a=add(a,b); }
int powMod(int x, int k) {
	int res = 1;
	for (;k;k >>= 1, x = mul(x, x)) if (k & 1) res = mul(res, x); 
	return res;
}
int inv(int x) { return powMod(x, P - 2); } 
int frac(int a,int b){ return mul(a, inv(b)); }
 
int n,a[N],b[N];
long long ans;
struct F{
bool operator()(int x,int y){return a[x]>a[y];}} fff;
priority_queue<int,vector<int>,F> Q;
 
void chk(int i){
	int l = (i - 1 + n) % n, r = (i + 1) % n;
	if(a[i]>b[i]&&a[i]-(a[l]+a[r])>=b[i])Q.push(i);
}
 
void calc(int i) {
	int l = (i - 1 + n) % n, r = (i + 1) % n;
	if(a[i]<b[i])return;
	int t = (a[i] - b[i]) / (a[l] + a[r]);
	a[i] -= t * (a[l] + a[r]),ans+=t;
	chk(l),chk(r);
}
 
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	freopen("d.in", "r", stdin); 
#endif
	read(n); 
	lop(i,0,n)read(b[i]);
	lop(i, 0, n) read(a[i]); 
	lop(i,0,n)chk(i);
	while(!Q.empty()){
		int t=Q.top();
		Q.pop();
		calc(t);
	//	lop(i,0,n)printf("%d ",b[i]);puts("");
	}
	bool suc=true;
	rep(i,1,n)suc&=a[i]==b[i];
	printf("%lld\n",suc?ans:-1);
	return 0;
}