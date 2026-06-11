#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll t1,t2,a1,a2,b1,b2;

int main(){
	cin>>t1>>t2>>a1>>a2>>b1>>b2;
	ll sa=t1*a1+t2*a2;
	ll sb=t1*b1+t2*b2;
	if(sa==sb){
		cout<<"infinity"<<endl;
		return 0;
	}
	if(sa<sb){
		swap(a1,b1);
		swap(a2,b2);
		swap(sa,sb);
	}
	if(a1>b1){
		cout<<0<<endl;
		return 0;
	}
	ll t=sa-sb,tmp=(b1-a1)*t1,res=1;
	tmp-=t;
	if(tmp>0){
		res+=(tmp+t-1)/t*2;
		tmp%=t;
	}
	if(tmp==0) res++;
	cout<<res<<endl;
}