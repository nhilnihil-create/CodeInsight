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
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vi a,b;

int main(){
	cin>>n;
	a=b=vi(n);
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	for(int i=2;i<n;i++) if(a[i-2]==b[i-2]&&a[i-1]==b[i-1]&&a[i]==b[i]){
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
}