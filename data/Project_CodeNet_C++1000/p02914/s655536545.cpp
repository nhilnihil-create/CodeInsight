#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))

#define DEBUG(x) cout<<#x<<": "<<(x)<<endl

int n;
ll a[125252];
bool used[125252];

int main(){
	scanf("%d",&n);
	REP(i,n)scanf("%lld",a+i);
	ll s = 0;
	REP(i,n)s ^= a[i];
	// base
	vl base;
	FORR(b,0,61){
		if(s>>b&1)continue;
		int p = -1;
		REP(i,n){
			if(used[i])continue;
			if(a[i]>>b&1){
				p = i;
				break;
			}
		}
		if(p==-1)continue;
		base.push_back(a[p]);
		used[p] = true;
		ll v = a[p];
		REP(i,n)if(a[i]>>b&1)a[i] ^= v;
	}
	ll y = 0;
	for(ll v : base){
		ll cur = (s^y) + y;
		ll nxt = (s^y^v) + (y^v);
		if(nxt > cur){
			y ^= v;
		}
	}
	printf("%lld\n", (s^y) + y);
	return 0;
}