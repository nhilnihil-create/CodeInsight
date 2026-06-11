#include <bits/stdc++.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	cin >> n >> m;
    vector<vector<int> > parts(m);

    for (int i = 0; i < n; i++) {
    	int days, reward;
    	cin >> days >> reward;

    	if (days <= m) {
    		parts[days - 1].push_back(reward);
    	}
    } 


    priority_queue<int> q;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
    	for (int j : parts[i]) {
    		q.push(j);
    	}

    	if (q.size()) {
    		ans += q.top();
    		q.pop();
    	}
    }

    cout << ans << "\n";

    return 0;
}