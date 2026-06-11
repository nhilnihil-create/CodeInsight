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
	V alp[26];
	int n=0;
	char c;
	while((c=getchar())!='\n'){
		alp[c-'a'].push_back(n);
		n++;
	}
	REP(i, 0, 26){
		if(alp[i].size()) alp[i].push_back(n+alp[i][0]);
		else alp[i].push_back(1e9);
	}

	ll ans = 0, now = -1;
	while((c=getchar())!='\n'){
		ll next = *std::upper_bound(ALL(alp[c-'a']), now);
		if(next==1e9){
			puts("-1");
			return 0;
		}
		ans += next - now;
		now = next % n;
	}
	printf("%ld\n", ans);
	return 0;
}

