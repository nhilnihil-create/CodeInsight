#include "bits/stdc++.h"
using namespace std;
vector<int>A[100005];
int main() {
	int N, M;
	cin >> N >> M;
	for (int n = 0; n < N ; ++n) {
		int a, b;
		cin >> a >> b;
		if (a > M) {
			continue;
		}
		A[M-a].push_back(b);
	}	
	priority_queue<int> q;
	long long ans = 0;
	for (int i = M - 1;i>=0;--i) {
		for (int m = 0; m < A[i].size();++m) {
			q.push(A[i][m]);
		}
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans <<endl;
	return 0;
}