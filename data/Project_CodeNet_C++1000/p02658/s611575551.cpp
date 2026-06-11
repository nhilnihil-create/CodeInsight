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
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vl a;

int main(){
	cin>>n;
	a=vl(n);
	for(auto &i:a) cin>>i;
	sort(a.begin(),a.end());
	if(a[0]==0) cout<<0<<endl;
	else{
		ll t=1;
		for(auto i:a){
			if(t<=1000000000000000000/i) t*=i;
			else t=0;
		}
		if(t==0) t=-1;
		cout<<t<<endl;
	}
}