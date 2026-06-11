#include <bits/stdc++.h>
#define INF pow(10, 9) + 7
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long int ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

void solve(){
	
	ll N, K;
	cin >> N >> K;
	vl A(N);
	rep(i, N) cin >> A[i];	
	
	rep(i, min(K, (ll)50)){
		
		vl acc(N);
		
		rep(i, N){
			acc[max((ll)0, i - A[i])] += 1;
			if(i + A[i] + 1 <= N - 1)  acc[i + A[i] + 1] -= 1;
		}

		A[0] = acc[0];
		rep2(i, 1, N) A[i] = acc[i] + A[i - 1];
		
	}
	
	rep(i, N) print(A[i]);

}	

int main(){
    
    fastio;
	solve();
    
	return 0;
	
}

