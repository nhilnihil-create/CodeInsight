#include <bits/stdc++.h>
using namespace std;

#define inf 1000*1000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	string s;
	cin >> n >> m >> s;

	// start from n, work backwards greedily
	vector<int> prev(n+1, -1);
	for(int i = n; i >= 0; i--) {
		if(s[i] == '1') {
			prev[i] = s[i+1] == '0' ? i+1 : prev[i+1];
		}
	}
	
	vector<int> ans;
	bool ok = true;
	int cur = n;
	while(cur > 0) {
		int jump = min(cur, m);
		int next = cur - jump;
		if(s[next] == '1') {
			next = prev[next];
			if(next == cur) {
				ok = false;
				break;
			}
			jump = cur - next;
		}
		
		ans.push_back(jump);
		cur = next;
	}
	
	reverse(ans.begin(), ans.end());
	int sz = ans.size();
	if(ok) {
		for(int i = 0; i < sz; i++) {
			cout << ans[i] << " \n"[i==sz-1];
		}
	} else {
		cout << -1 << endl;
	}
}
