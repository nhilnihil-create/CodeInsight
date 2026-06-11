#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

	vector<vector<int>> v(1e5 + 1);
	for (int i = 0; i < N; i++) v[A[i]].push_back(B[i]);

	priority_queue<int> pq;
	int ret = 0;

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			pq.push(v[i][j]);
		}
		if (pq.empty() == 0) {
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << endl;
}