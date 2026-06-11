#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;cin >> n;
	int m;cin >> m;
	ll k;cin >> k;
	vector<ll> a = vector<ll>(n);
	vector<ll> b = vector<ll>(m);
	vector<ll> asum = vector<ll>(n+1);
	vector<ll> bsum = vector<ll>(m+1);
	asum[0] = 0;
	bsum[0] = 0;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		asum[i+1] = asum[i] + a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
		bsum[i+1] = bsum[i] + b[i];
	}

	int ans = 0;
	int bestj = m;
	for(int i = 0; i <= n; i++){
		for(int j = bestj; j > -1; j--){
			if(asum[i] + bsum[j] <= k){
				ans = max(ans,i+j);
				bestj = j;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
