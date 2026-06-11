#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

void solve(){
	
	ll N, K;
	ll ans = 0;
	cin >> N >> K;
	vvl nxt(60, vl(N));
	rep(i, N) cin >> nxt[0][i];
	rep(i, N) nxt[0][i]--;
	rep2(i, 1, 60) rep(j, N) nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
	rep(i, 60) if(K & (1LL << i)) ans = nxt[i][ans];
	print(ans + 1);
	
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}
