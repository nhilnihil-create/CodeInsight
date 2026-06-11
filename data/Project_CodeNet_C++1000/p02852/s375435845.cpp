// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int dp[N], go[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	string s;
	
	cin >> s;

	go[0] = -1;

	deque<pair<int,int>> dq;
	dq.push_back(make_pair(n, 0));
	

	for(int i = n - 1; i >= 0; i--) {
		if(s[i] == '1') continue;
		while(dq.size() && dq.front().first > i + m) dq.pop_front();
		if(dq.empty()) {
			cout << -1;
			exit(0);
		}
		go[i] = dq.front().first;
		int now = dq.front().second + 1;
		while(dq.size() && dq.back().second >= now) dq.pop_back();
		dq.push_back(make_pair(i, now));
	}

	if(go[0] == -1) {
		cout << -1;
		exit(0);
	}

	int now = 0;
	while(now != n) {
		cout << go[now] - now << " ";
		now = go[now];
	}
	return 0;
}
