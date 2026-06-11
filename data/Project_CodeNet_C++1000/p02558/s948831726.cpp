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

#include<atcoder/dsu>
using namespace atcoder;

int n,q;

int main(){
	cin>>n>>q;
	dsu uft(n);
	for(int i=0;i<q;i++){
		int t,u,v;
		cin>>t>>u>>v;
		if(t==0) uft.merge(u,v);
		else cout<<uft.same(u,v)<<endl;
	}
}