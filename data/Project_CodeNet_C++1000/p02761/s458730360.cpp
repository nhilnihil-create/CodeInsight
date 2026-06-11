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

	ll N, M;
	cin >> N >> M;
	vl v(N, -1);
	rep(i, M){
		ll in1, in2;
		cin >> in1 >> in2;
		if(v[in1 - 1] != -1 && v[in1 - 1] != in2){
			print(-1);
			return;
		}
		v[in1 - 1] = in2;
	}
	
	string ans = "";
	
	if(N == 1 && M == 1 && v[0] == 0){
		print(0);
		return;
	}	
	
	if(v[0] == 0){
		print(-1);
		return;
	}
	
	if(N == 1 && M == 0){
		print(0);
		return;
	}
	
	rep(i, N){
		if(v[i] != -1) ans += to_string(v[i]);
		else{
			if(i == 0) ans += '1';
			else ans += '0';
		}
	}
	
	print(ans);
	
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Main();
    
	return 0;
	
}



