#include <bits/stdc++.h>
using namespace std;
const int maxn = 600300;
int c[maxn], pos[maxn], pr[maxn], ans[maxn];
int main(){
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		c[x]++;
	}
	vector<int> occ;
	for(int i = 0; i < maxn; i++){
		if(c[i]){
			occ.push_back(c[i]);
		}
	}
	sort(occ.begin(), occ.end());
	int len = occ.size();
	for(int i = 1; i <= 2 * n; i++){
		pos[i] = lower_bound(occ.begin(), occ.end(), i) - occ.begin();
	}
	pr[0] = occ[0];
	for(int i = 1; i < len; i++) pr[i] = pr[i - 1] + occ[i];
	for(int k = 1; k <= n; k++){
		int p = lower_bound(occ.begin(), occ.end(), k) - occ.begin();
		int s = 0;
		if(p) s += pr[p - 1] / k;
		s += len - p;
		ans[s] = max(ans[s], k);
	}
	for(int i = n; i >= 1; i--){
		ans[i] = max(ans[i], ans[i + 1]);
	}
	for(int i = 1; i <= n; i++){
		ans[i + 1] = min(ans[i], ans[i + 1]);
		cout << ans[i] << endl;
	}
	return 0;
}
