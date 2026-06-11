#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

int main(){//Refering other editorials.
	int n;
	llong k;
	cin>>n>>k;
	
	vector<llong> a(n),f(n);
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>f[i];
	sort(ALL(a));
	sort(ALL(f),greater<llong>());
	
	llong l=-1LL,r=1e18;
	while(r-l>1){
		llong mid=(l+r)/2;
		llong need=0LL;
		REP(i,n){
			llong hoge=mid/f[i];
			if(a[i]-hoge>0) need+=a[i]-hoge;
		}
		
		if(need>k) l=mid;
		else r=mid;
	}
	
	cout<<r<<endl;
}