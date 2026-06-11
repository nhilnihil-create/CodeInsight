#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
vector<llint> G[100005];

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint ans = 1;
void dfs(int v, int p)
{
	llint cnt = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		cnt++;
		dfs(G[v][i], v);
	}
	llint rem = k-1;
	if(v != 1) rem--;
	if(cnt > rem) ans = 0;
	else{
		ans *= comb(rem, cnt) * fact[cnt] % mod, ans %= mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> k;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	ans = k;
	dfs(1, -1);
	
	cout << ans << endl;
	
	return 0;
}