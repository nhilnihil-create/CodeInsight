#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	priority_queue<pair<int, int>> pq;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		pq.push({x, 0});
	}
	while(k--) {
		pair<int, int> cur = pq.top();
		if(cur.first == 0)
			break;
		pq.pop();
		pq.push({cur.first / 2, cur.second + 1});
	}
	long long answer = 0;
	while(!pq.empty()) {
		answer += pq.top().first;
		pq.pop();
	}
	cout << answer;
}
