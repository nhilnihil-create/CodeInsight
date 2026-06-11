// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	priority_queue<int> pq;

	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	long long ans = 0;

	while(m--) {
		int now = pq.top();
		pq.pop();
		pq.push(now / 2);
	}

	while(pq.size()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;



	return 0;
}
