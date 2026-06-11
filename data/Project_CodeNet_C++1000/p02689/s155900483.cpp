#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve(){
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> roads(n+1);
	vector<ll> heights(n+1);
	for(int i = 1; i <= n; ++i) cin >> heights[i];
	for(int i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		roads[a].emplace_back(b);
		roads[b].emplace_back(a);
	}
	
	ll goods = 0;
	for(int i = 1; i <= n; ++i) {
		if(roads[i].empty()) {
			++goods;
			continue;
		}
		int j = 0;
		for(; j < (int)roads[i].size(); ++j) {
			if(heights[roads[i][j]] >= heights[i]) break;
		}
		if(j == (int)roads[i].size()) {
			++goods;
		}
	}
	
	cout << goods;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	solve();
    
    return 0;
}
