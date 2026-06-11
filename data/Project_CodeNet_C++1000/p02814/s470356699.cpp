// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) {rep(_,v.size())cout<<" "<<v[_];cout<<endl;}
#define show2d(v) {rep(__,v.size())show1d(v[__]);}
using namespace std;
//kaewasuretyuui
typedef long long ll;
#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
#define mt make_tuple
typedef tuple<int,int,int> tp;
typedef vector<tp> vt;
typedef vector<vt>vvt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
#define yes cout<<"Yes\n"
#define no cout<<"No\n"

//nCr mod m
#define MOD 998244353
#define M 220000
vector<ll> fact;
bool h=false;
void init(){
	h=true;
	fact=vector<ll>(M);
	fact[0]=fact[1]=1;
	loop(i,2,M)fact[i]=fact[i-1]*i%MOD;
}
// a^b mod MOD
ll powmod(ll a,ll b,ll m=MOD){
	ll out=1;
	ll p=a%m;
	while(b){
		if(b&1)out=out*p%m;
		p=p*p%m;
		b>>=1;
	}
	return out;
}
//nCr
ll nCr(ll n,ll r,ll m=MOD){
	if(!h)init();
	if(n<0||r<0||n<r)return 1;//??????
	ll out=fact[n]*powmod(fact[r]*fact[n-r]%m,m-2,m)%m;
	return out;
}
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
vi dp(1000,-1);
int f(int a){
	if(dp[a]+1)return dp[a];
	return dp[a]=powmod(fact[a],MOD-2,MOD);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	int t=1;
	bool x=0,y=0;
	vi in(n);
	rep(i,n){
		int a;cin>>a;
		in[i]=a;
		if(a/2%2)x=1;
		else y=1;
		t=lcm(t,a/2);
		if(t>m){
			cout<<0<<endl;
			return 0;
		}
	}
	bool h=true;
	rep(i,n)if((t-in[i]/2)%in[i])h=false;
	if(h)cout<<(m+t)/(t*2)<<endl;
	else cout<<0<<endl;
}
