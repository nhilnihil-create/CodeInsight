#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<string, int>> v(n);
	for(auto &x:v) cin >> x.first >> x.second;
	string p; cin >> p;
	bool found = false; int ans = 0;
	for(int i=0;i<n;i++){
		if(v[i].first == p){
			found = true;
			continue;
		}
		if(found) ans += v[i].second;
	}
	cout << ans << "\n";
	return 0;
}
