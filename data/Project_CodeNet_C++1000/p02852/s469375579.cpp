#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll N,M;
	string S;
	cin >> N >> M >> S;

	vector<ll> ind;
	for(int i=0;i<N+1;i++){
		if(S[i]=='0'){
			ind.push_back(i);
		}
	}

	vector<ll> ans;
	ll now = N;
	while(now){
		ll to = ind[upper_bound(ind.begin(),ind.end(),now-M-1)-ind.begin()];
		if(to == now){
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(now - to);
		now = to;
	}
	reverse(ans.begin(), ans.end());
	cout << ans[0];
	for(int i=1;i<ans.size();i++){
		cout << " " << ans[i];
	}
	cout << endl;
}