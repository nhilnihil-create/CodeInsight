/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define pub push_back
#define pob pop_back
#define mak make_pair

typedef long long ll;
typedef long double lf;
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

struct BinIdxTree{
	ll dt[1<<18];
	void add(int a,ll x){
		while(a<(1<<18)){
			dt[a]+=x;
			a+=a&-a;
		}
	}
	ll sum(int a){
		ll res=0;
		while(a){
			res+=dt[a];
			a-=a&-a;
		}
		return res;
	}
}bit;

int n,d,a;
pair<ll,ll> g[1<<18];
ll ans=0;

int main(){
	scanf("%d%d%d",&n,&d,&a);
	cont(i,n)scanf("%lld%lld",&g[i].first,&g[i].second);
	sort(g+1,g+n+1);
	cont(i,n){
		ll tm=(g[i].second-bit.sum(i)+a-1)/a;
		if(tm<=0)continue;ans+=tm;
		ll lim=g[i].first+2ll*d;
		int rpos=upper_bound(g+1,g+n+1,mak(lim,INF))-g;
		bit.add(i,tm*a);
		bit.add(rpos,-tm*a);
	}
	return 0&printf("%lld\n",ans);
}