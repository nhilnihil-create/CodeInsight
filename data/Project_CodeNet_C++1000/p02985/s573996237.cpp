#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, K;
ll ans;
vector<ll> to[100005];

void dfs(ll pa, ll cur) {
	ll col;
	if(pa == -1) {
		col = K-1;
	} else {
		col = K - 2;
	}

	for(ll next: to[cur]) {
		if(next == pa) continue;
		ans *= col;
		ans %= DIV;
		col--;
		dfs(cur, next);
	}
}

int main(){
	cin >> N >> K;

	rep(i, N - 1) {
		ll a, b;
		cin >> a >> b;
		a--;b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	ans = K;
	dfs(-1, 0);
	cout << ans << endl;
}