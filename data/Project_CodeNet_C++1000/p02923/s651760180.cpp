#include <bits/stdc++.h>
#define INF 1000000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(i, vec.size()) cout << vec[i] << " "; print("");
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

void Main(){

	ll N;
	cin >> N;
	vl v(N);
	rep(i, N) cin >> v[i];
	
	ll ans = 0;
	ll cnt = 0;
	ll ma = v[0];
	
	rep2(i, 1, N){
		if(ma >= v[i]) cnt += 1;
		else cnt = 0;
		ma = v[i];
		chmax(ans, cnt);
	}

	print(ans);
		
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
    
	return 0;
	
}



