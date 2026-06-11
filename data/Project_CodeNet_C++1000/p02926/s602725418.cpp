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
typedef pair<ll,pll> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
vi x,y;
vector<pair<double,int>> a;

int main(){
	cin>>n;
	x=y=vi(n);
	int B=0;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		if(x[i]==0&&y[i]==0) B++;
		else a.push_back(make_pair(atan2(y[i],x[i]),i));
	}
	n-=B;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	sort(a.begin(),a.end());
	ll res=0;
	for(int i=0;i<n;i++){
		ll X=0,Y=0;
		for(int j=0;j<n;j++){
			X+=x[a[(i+j)%n].second];
			Y+=y[a[(i+j)%n].second];
			res=max(res,X*X+Y*Y);
		}
	}
	cout<<syosu(12)<<sqrt(res)<<endl;
}