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

int n,k;
vi a;

int main(){
	cin>>n>>k;
	a=vi(n);
	for(auto &i:a) cin>>i;
	for(int i=0;i<k&&a!=vi(n,n);i++){
		vi b(n);
		for(int j=0;j<n;j++){
			int l=j-a[j],r=j+a[j]+1;
			l=max(l,0);
			b[l]++;
			if(r<n) b[r]--;
		}
		for(int j=1;j<n;j++) b[j]+=b[j-1];
		a=b;
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i==n-1];
}