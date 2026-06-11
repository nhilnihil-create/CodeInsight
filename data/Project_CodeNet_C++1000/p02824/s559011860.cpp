#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005;
ll q[N],a[N],m,v,p;
int n;
bool check(int x){
	int qq=0;
	if(v>=p){
		For(i,p,n)if(i!=x){
			q[++qq]=a[x]+m-a[i];
		}
		int vv=v-(p-1); ll sum=0;
		For(i,1,qq){
			if(q[i]<0)return 0;
			sum+=q[i];
			if(sum<(ll)(vv-(qq-i))*m)return 0;
		}
		return 1;
	}else{
		return a[x]+m>=a[p];
	}
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	cin>>n>>m>>v>>p; v--;
	For(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int l=p,r=n;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(check(mid))l=mid; else r=mid-1;
	}
	cout<<l<<endl;
}
