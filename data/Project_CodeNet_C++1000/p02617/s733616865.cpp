#include <bits/stdc++.h>
using namespace std;
#define MIN INT_MIN
#define MAX INT_MAX
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define E "\n"
#define frep(i,j,k,inc) for(int i=j;i<k;i+=inc)
#define rrep(i,j,k,dec) for(int i=j;i>k;i-=dec)
#define arep(elm,obj) for(auto elm:obj)
#define all(x) x.begin(),x.end()
#define revT greater<int>()
#define SMAX 1000000
#define EMAX 101

typedef uint64_t usf;
typedef int64_t isf;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int>pii;
const ll mod=1000000007;
void solve();
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
//    int t;cin>>t;while(t--)
    {solve();}return 0; }

int mima(vi vec,int f){int mi=vec[0],ma=vec[0];frep(i,1,vec.size(),1){mi=min(mi,vec[i]);ma=max(ma,vec[i]);}if(f){return ma;}else{return mi;}}
template <class T>
T gcd(T a,T b){return __gcd(a,b);}
template <class T>
T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T>
T miller(T d,T n,T a){T x=mpow(a,d,n);if(x==1 || x==n-1){return true;}while(d!=n-1){x=(x*x)%n;d*=2;if(x==1){return false;}if(x==n-1){return true;}}return false;}
template <class T>
T isprime(T n){if(n<=1 || n==4){return false;}if(n<=3){return true;}T d=n-1;while(d%2==0){d/=2;}T arr109[3]={2,7,61};T arr264[12]={2,3,5,7,11,13,17,19,23,29,31,37};for(auto x:arr109){if(!miller(d,n,x)){return false;}}return true;}
bool earr[EMAX+1];void eseive() {memset(earr, 1, sizeof(earr));earr[0] = 0;earr[1] = 0;frep(i, 2, sqrt(EMAX) + 1, 1) {frep(j, i * i, EMAX + 1, i) {earr[j] = 0;}}frep(i, 0, EMAX + 1, 1) {if (earr[i]) {cout << i << E;}}}
int spf[SMAX]={0};
void pseive(){spf[1]=1;frep(i,2,SMAX,1){spf[i]=i;}frep(i,4,SMAX,2){spf[i]=2;}for(int i=3;i*i<SMAX;i++){if(spf[i]==i){for(int j=i*i;j<SMAX;j+=i){if(spf[j]==j){spf[j]=i;}}}}}
vi fastfactor(int n){vi ret;while(n!=1){ret.PB(spf[n]);n/=spf[n];}return ret;}
template <class T>
T minv1(T a,T m){T temp=m,q,t,u=0,v=1;if(m==1){return 0;}while(a>1){q=a/m;t=m;m=a%m;a=t;t=u;u=v-q*u;v=t;}if(v<0){v+=temp;}return v;}
template <class T>
T mmul(T a,T b,T m){T res=0;a%=m;while(b){if(b&1){res=(res+a)%m;}a=(2*a)%m;b>>=1;}return res%m;}
template <class T>
T mpow(T a,T n,T m){T res=1;a%=m;if(!a){return 0;}while(n){if(n&1){res=mmul(res,a,m);}n=n>>1;a=mmul(a,a,m);}return res;}
template <class T>
T minv2(T a, T m){return mpow(a,m-2,m);}

void solve(){ 
	usf n;
	cin>>n;
	usf ans=0;
	for(usf i=0;i<n;i++){ans+=((i+1)*(n-i));}
	frep(i,0,n-1,1){
		usf a,b;
		cin>>a>>b;
		a--;b--;
		if(a>b){swap(a,b);}
		ans-=(a+1)*(n-b);	
	}
	cout<<ans<<E;
}