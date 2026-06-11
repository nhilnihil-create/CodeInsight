#pragma target("avx")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define rep(i,b,e) for(ll i=b; i<e; i++)
#define be(vec) vec.begin(),vec.end()
#define print(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define scan(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	ll n, d, a;
	scanf("%ld %ld %ld", &n, &d, &a);
	std::vector<P> xh(n);
	rep(i, 0, n) scanf("%ld %ld", &xh[i].fi, &xh[i].se);
	std::sort(be(xh));

	V b(n, 0);
	ll bius = 0, ans = 0;
	rep(i, 0, n){
		bius -= b[i];
		xh[i].se = std::max(0l, xh[i].se - bius * a);
		ll x = (xh[i].se + a - 1) / a;
		ans += x;
		bius += x;
		ll idx = std::upper_bound(be(xh), P(xh[i].fi+2*d,1e10)) - xh.begin();
		if(idx<n) b[idx] += x;
	}
	printf("%ld\n", ans);
	return 0;
}
