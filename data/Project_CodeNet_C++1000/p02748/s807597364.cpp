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
	int a, b, m;
	scanf("%d %d %d", &a, &b, &m);
	V A(a), B(b);
	ll mina = 1e9, minb = 1e9;
	REP(i, 0, a){
		scanf("%ld", &A[i]);
		mina = std::min(mina, A[i]);
	}
	REP(i, 0, b){
		scanf("%ld", &B[i]);
		minb = std::min(minb, B[i]);
	}
	ll ans = mina + minb;
	REP(i, 0, m){
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		ans = std::min(ans, A[x-1]+B[y-1]-c);
	}
	printf("%ld\n", ans);
	return 0;
}

