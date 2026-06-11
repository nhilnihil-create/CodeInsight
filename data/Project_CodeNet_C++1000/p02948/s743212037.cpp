#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	//read ans
	int N, M;
	cin >> N >> M;
	vector<vector<int>> Works(M);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > M) continue;
		else Works[a - 1].push_back(b);
	}
	long long ans = 0;
	priority_queue<int> Q;
	for (int i = 0; i < M; i++) {
		for (int w : Works[i]) Q.push(w);
		if (Q.empty()) continue;
		ans += Q.top();
		Q.pop();
	}
	cout << ans << endl;
}