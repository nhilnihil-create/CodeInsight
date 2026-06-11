#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
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
const ll INF=1ll<<55;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll t1,t2,a,b,c,d;

int main(){
	cin>>t1>>t2>>a>>b>>c>>d;
	ll tmp1=t1*a+t2*b,tmp2=t1*c+t2*d;
	if(tmp1==tmp2){
		cout<<"infinity"<<endl;
		return 0;
	}
	if(tmp1>tmp2){
		swap(a,c);
		swap(b,d);
		swap(tmp1,tmp2);
	}
	ll d=tmp2-tmp1;
	ll m=t1*a-t1*c;
	if(m<0){
		cout<<0<<endl;
	}
	else{
		ll res=1;
		m-=d;
		if(m>=0){
			ll t=m/d;
			res+=t*2;
			m-=t*d;
			if(m==0) res++;
			if(m>0) res+=2;
		}
		cout<<res<<endl;
	}
}