#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;cin >> n;
	int m;cin >> m;
	ll x;cin >> x;
	vector<ll> c = vector<ll>(n,0);
	vector<vector<ll>> a(n,vector<ll>(m,0));

	for(int i = 0; i < n; i++){
		cin >> c[i];
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	ll ans = 9999999;
	for(int i = 0; i < (2<<n); i++){
		bool flag = true;
		for(int j = 0; j < m; j++){
			ll asum = 0;
			for(int k = 0; k < n; k++){
				if(i>>k&1){
					asum += a[k][j];
				}
			}
			if(asum < x){
				flag = false;
				break;
			}
		}
		if(flag){
			ll csum = 0;
			for(int j = 0; j < n; j++){
				if(i>>j&1){
					csum += c[j];
				}
			}
			ans = min(csum,ans);
		}
	}

	if(ans != 9999999){
		cout << ans << endl;
	}else{
		cout << "-1" << endl;
	}

	return 0;
}
