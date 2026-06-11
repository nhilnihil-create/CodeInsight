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
const int maxn = 5005;
const int maxm = 100;
const int inf = 2147483647;
typedef long long ll;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}
int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	FOR(i,0,n)scanf("%d",&a[i]);
	sort(a,a+n);
	ll cnt=0;
	FOR(i,0,n)
	FOR(j,i+1,n){
		int t=lower_bound(a,a+n,a[i]+a[j])-a;
		cnt+=n-t;
	}
	cnt=(ll)n*(n-1)*(n-2)/6ll-cnt;
	printf("%lld\n",cnt);
}
