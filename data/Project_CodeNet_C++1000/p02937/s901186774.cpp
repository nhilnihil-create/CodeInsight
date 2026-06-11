#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

signed main(){
	string s, t; cin >> s >> t;
	vector<vector<lint> > data(26);
	vector<lint> cs(26, 0), ct(26, 0);
	lint N = s.size(), M = t.size();
	for(lint i = 0; i < N; i++) data[s[i] - 'a'].push_back(i + 1), cs[s[i] - 'a']++;
	for(lint i = 0; i < M; i++) ct[t[i] - 'a']++;
	for(lint i = 0; i < 26; i++){
		if(cs[i] == 0 && ct[i] != 0){
			cout << -1 << endl;
			return 0;
		}
	}
	lint ans = 0, index = 0;
	for(lint i = 0; i < M; i++){
		lint x = t[i] - 'a';
		lint next = upper_bound(data[x].begin(), data[x].end(), index) - data[x].begin();
		if(next == data[x].size()) ans += (N - index + data[x][0]), index = data[x][0];
		else ans += data[x][next] - index, index = data[x][next];
	}
  cout << ans << endl;
}