#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> p(n), c(n);
	for(int i=0; i<n; i++) cin >> p[i], --p[i];
	for(int i=0; i<n; i++) cin >> c[i];

	ll ans = -INF;

	for(int i=0; i<n; i++){
		int v = i;
		ll cycle_sum = 0;
		int cycle_cnt = 0;

		while(true){
			cycle_cnt++;
			cycle_sum += c[v];
			v = p[v];
			if(v == i) break;
		}

		ll path = 0;
		int cnt = 0;

		while(true){
			cnt++;
			path += c[v];

			if(cnt > k) break;

			int num = (k-cnt)/cycle_cnt;
			ll score = path + max(0ll, cycle_sum)*num;
			ans = max(ans, score);

			v = p[v];
			if(v==i) break;
		}
	}

	cout << ans << endl;
	return 0;
}