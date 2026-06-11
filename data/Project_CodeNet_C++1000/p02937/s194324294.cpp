#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
	string s, t; cin >> s >> t;
	lint N = s.size(), M = t.size();
	vector<lint> cs(26, 0), ct(26, 0);
	vector<vector<lint> > alp(26);
	for(lint i = 0; i < N; i++){
		cs[s[i] - 'a']++;
		alp[s[i] - 'a'].push_back(i + 1);
	}
	for(lint i = 0; i < M; i++) ct[t[i] - 'a']++;
	for(lint i = 0; i < 26; i++){
		if(cs[i] == 0 && ct[i] != 0){
			cout << -1 << endl;
			return 0;
		}
	}
	lint ans = 0, counter = 1;
	for(lint i = 0; i < M; i++){
		lint j = t[i] - 'a';
		lint v = lower_bound(alp[j].begin(), alp[j].end(), counter) - alp[j].begin();
		if(v == alp[j].size()){
			ans += ((N - counter + 1) + alp[j][0]);
			counter = alp[j][0] + 1;
		}
		else{
			ans += (alp[j][v] - counter + 1);
			counter = alp[j][v] + 1;
		}
	}
	cout << ans << endl;
}