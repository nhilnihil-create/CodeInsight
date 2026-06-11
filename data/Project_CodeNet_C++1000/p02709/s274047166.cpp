#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int max_n = 2005;
ll dp[max_n][max_n];
inline void chmax(ll& a, ll b){
	a = max(a, b);
}

int main(){
	int n;

	cin >> n;

	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	for(int i=0; i<n+1; i++){
		for(int j=0; j<n+1; j++){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;

	vector<P> p;
	for(int i=0; i<n; i++){
		p.emplace_back(a[i], i);
	}
	sort(p.rbegin(), p.rend());

	for(int i=0; i<n; i++){
		int pi = p[i].second;
		for(int l=0; l<i+1; l++){
			int r = i - l;
			chmax(dp[i+1][l+1], dp[i][l]+ll(pi-l)*a[pi]);
			chmax(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]);
		}
	}

	ll ans = 0;
	for(int i=0; i<n+1; i++){
		chmax(ans, dp[n][i]);
	}
	cout << ans << endl;
	return 0;
}

