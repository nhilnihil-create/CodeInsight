#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
	int n,ans=0;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;++i) cin >> v[i];
	for(int i=1;i<n-1;++i){
		if(v[i] != max({v[i],v[i+1],v[i-1]}) && v[i] != min({v[i],v[i+1],v[i-1]}))
			++ans;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){ 
		solve();
	}
	return 0;
}