#include <bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
#define pi pair<ll,int>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 100005;
const int maxm = 1000005;
const int inf = 2147483647;
typedef long long ll;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}


int main(){
	ll s,x1,x2,y1,y2;
	scanf("%lld",&s);
	if(s<=1e9)printf("%lld %lld %lld %lld %lld %lld\n",0,0,1,0,0,s);
	else if(s==1000000000000000000ll)printf("%lld %lld %lld %lld %lld %lld\n",0ll,0ll,1000000000ll,0ll,0ll,1000000000ll);
	else printf("%lld %lld %lld %lld %lld %lld\n",0ll,0ll,s/(1000000000ll)+1,(s/1000000000ll+1)*(1000000000ll)-s,1,1000000000ll);
}
