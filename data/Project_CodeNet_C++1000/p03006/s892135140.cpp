#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<ll,P>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define REP(i,b,e) for(ll i=b; i<e; i++)
#define ALL(vec) vec.begin(),vec.end()
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n;
	scanf("%d", &n);
	std::vector<P> xy(n);
	REP(i, 0, n) scanf("%ld %ld", &xy[i].fi, &xy[i].se);
	
	std::map<P, int> mp;
	REP(i, 0, n) REP(j, 0, n) if(i!=j) {
		ll dx = xy[i].fi-xy[j].fi, dy = xy[i].se-xy[j].se;
		mp[P(dx,dy)]++;
	}

	int ans = n;
	for(auto pd: mp){
		ans = std::min(ans, n-pd.se);
	}
	printf("%d\n", ans);
	return 0;
}

