#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<pair<ll,ll>> zahyo(n);
	rep(i,n) {
		ll x, y;
		cin >> x >> y;
		zahyo[i] = make_pair(x,y);
	}
	
	int ans = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(i == j) continue;
			ll p = zahyo[i].first - zahyo[j].first;
			ll q = zahyo[i].second - zahyo[j].second;
			int count = 0;
			for (int k = 0; k < n; ++k) {
				for (int l = 0; l < n; ++l) {
					if(k == l) continue;
					ll dx = zahyo[k].first - zahyo[l].first;
					ll dy = zahyo[k].second - zahyo[l].second;
					if(dx == p && dy == q){
						count++;
					}
				}
			}
			ans = max(ans, count);
		}
	}
	
	cout << n - ans << endl;
	
	return 0;
}

