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

int f(vl a){
	int n=a.size();
	sort(a.begin(),a.end());
	if(n%2==1) return a[n/2];
	return (a[n/2-1]+a[n/2])/2;
}

ll n;
vl a,b;

int main(){
	cin>>n;
	a=b=vl(n);
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	if(n%2==0) for(int i=0;i<n;i++) a[i]*=2,b[i]*=2;
	int l=f(a),r=f(b);
	cout<<r-l+1<<endl;
}