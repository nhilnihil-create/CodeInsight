#include <bits/stdc++.h>
#define INF 1000000007
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define print(x) cout << x << "\n"
#define print2(x, y) cout << x << " " << y << "\n"
#define printv(vec) rep(lp, vec.size()) cout << vec[lp] << " "; print(""); 
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

map<ll, ll> prime_fact(ll n) {
	map<ll, ll> ret;
	rep2(i, 2, sqrt(n)){
		while (n % i == 0){
			ret[i]++;
			n /= i;
		}
	}
	if(n != 1) ret[n]++;
	return ret;
}

void Main(){
 
	ll A, B;
	cin >> A >> B;
	
	map<ll, ll> ma = prime_fact(A);
	ll ans = 1;
	for(auto itr = ma.begin(); itr != ma.end(); itr++){
		ll key = itr -> first;
		ans += (B % key == 0);
	}
	print(ans);
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
	return 0;
	
}



