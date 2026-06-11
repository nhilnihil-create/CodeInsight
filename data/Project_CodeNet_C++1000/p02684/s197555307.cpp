#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define printv(vec) rep(i, vec.size()){cout << vec[i] << " ";} print("");
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
	
	ll N, K, ans, mod, cnt, nx, loop_cnt;
	cin >> N >> K;
	vl A(N);
	rep(i, N) cin >> A[i];
	rep(i, N) A[i] -= 1;
	
	vl visited(N, -1);
	vl v(0);
	cnt = 0;
	nx = 0;
	while(visited[nx] < 0){
		v.push_back(nx);
		visited[nx] = cnt;
		nx = A[nx];
		cnt += 1;
	}
	if(cnt > K) ans = v[K];
	else{
		loop_cnt = cnt - visited[nx];
		mod = (K - cnt) % loop_cnt;
		ans = v[visited[nx] + mod];
	}
	print(ans + 1);
	
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}
