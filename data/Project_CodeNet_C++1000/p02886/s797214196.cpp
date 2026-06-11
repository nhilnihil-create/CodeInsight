#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+7;

void solve(){
	int n;cin >> n;
	ll ans = 0;
	vector<int> hash(n);
	for(auto &x:hash) cin >> x;
	for(int i = 0;i<n;++i){
		for(int j = i+1;j<n;++j){
			ans += hash[i]*hash[j];
		}
	}
	cout << ans << '\n';}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t=1;
//	int t;cin >> t;
	while(t--) solve();
}

