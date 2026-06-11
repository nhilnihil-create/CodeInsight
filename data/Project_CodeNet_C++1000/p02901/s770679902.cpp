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
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<P> keys(m);
	REP(i, 0, m){
		ll cost, cnt, key = 0;
		scanf("%ld %ld", &cost, &cnt);
		REP(j, 0, cnt){
			int num;
			scanf("%d", &num);
			key |= (1<<(num-1));
		}
		keys[i] = P(cost, key);
	}

	ll dp[1+m][1<<n];
	REP(i, 0, 1+m) REP(j, 0, 1<<n) dp[i][j] = INF;
	dp[0][0] = 0;
	REP(i, 0, m){
		REP(j, 0, 1<<n){
			dp[i+1][j] = std::min(dp[i+1][j], dp[i][j]);
			dp[i+1][j|keys[i].se] = std::min(dp[i+1][j|keys[i].se], dp[i][j]+keys[i].fi);
		}
	}
	if(dp[m][(1<<n)-1]==INF) puts("-1");
	else printf("%ld\n", dp[m][(1<<n)-1]);
	return 0;
}

