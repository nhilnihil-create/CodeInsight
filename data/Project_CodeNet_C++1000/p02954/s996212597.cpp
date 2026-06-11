#include <bits/stdc++.h>
#define INF 100000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = inx(x, y)
#define print(x) cout << x << "\n"
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
using vvs = vector<vector<string>>;

void solve(){
	
	string S;
	cin >> S;
	ll length = S.size();
	vvl v(60, vl(length));
	vl ans(length);
	rep(i, length){
		if(S[i] == 'R') v[0][i] = i + 1;
		else v[0][i] = i - 1;
	}
	rep(i, 59) rep(j, length) v[i + 1][j] = v[i][v[i][j]];
	rep(i, length) ans[v[59][i]] += 1;
	printv(ans);
	
}	

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
    
	return 0;
	
}