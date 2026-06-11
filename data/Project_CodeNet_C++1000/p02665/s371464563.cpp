#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
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
const int inf=1<<29;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vl a,b;

int main(){
	cin>>n;
	a=b=vl(n+1);
	for(auto &i:a) cin>>i;
	if(n==0){
		if(a[0]==1) cout<<1<<endl;
		else cout<<-1<<endl;
		return 0;
	}
	if(a[0]){
		cout<<-1<<endl;
		return 0;
	}
	b[0]=1;
	for(int i=1;i<=n;i++){
		b[i]=min(INF,2*b[i-1]-a[i]);
		if(b[i]<0){
			cout<<-1<<endl;
			return 0;
		}
	}
	ll t=0,res=1;
	for(int i=n;i>0;i--){
		t+=a[i];
		res+=t;
		if((t+1)/2>b[i-1]){
			cout<<-1<<endl;
			return 0;
		}
		if(t>b[i-1]) t=b[i-1];
	}
	if(t!=1) res=-1;
	cout<<res<<endl;
}