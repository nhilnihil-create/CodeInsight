#include <bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
#define pi pair<int,int>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 100005;
const int maxm = 100;
const int inf = 2147483647;
typedef long long ll;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}
ll a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	ll sm=0;
	FOR(i,0,n){
		scanf("%d",&a[i]);
		if(i%2==0)sm+=a[i];else sm-=a[i];
	}
	printf("%lld ",sm);
	FOR(i,0,n-1){
		sm=a[i]*2-sm;
		printf("%lld ",sm);
	}
	printf("\n");
}
