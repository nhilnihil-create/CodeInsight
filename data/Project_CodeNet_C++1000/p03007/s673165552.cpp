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
	V a(n);
	SCAN(a);
	std::sort(ALL(a));
	std::reverse(ALL(a));

	int mid = n-1;
	for(int i=n-1; i>0; i--) if(a[i]<=0) mid = i;
	
	ll ans = 0;
	REP(i, 0, n){
		if(i<mid) ans += a[i];
		else ans -= a[i];
	}
	printf("%ld\n", ans);

	ll cnt = a[mid];
	for(int i=mid-1; i>0; i--){
		printf("%ld %ld\n", cnt, a[i]);
		cnt -= a[i];
	}
	printf("%ld %ld\n", a[0], cnt);
	cnt = a[0] - cnt;

	for(int i=mid+1; i<n; i++){
		printf("%ld %ld\n", cnt, a[i]);
		cnt -= a[i];
	}
	return 0;
}

