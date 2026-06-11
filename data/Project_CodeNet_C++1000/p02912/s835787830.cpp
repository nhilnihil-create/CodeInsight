#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N, M;
	cin >> N >> M;

	priority_queue<int64_t> pq;
	for (int i = 0; i < N; i++) {
		int64_t n;
		cin >> n;
		pq.push(n);
	}

	for (int i = 0; i < M; i++) {
		int64_t n = pq.top();
		pq.pop();
		pq.push(n / 2);
	}

	int64_t sum = 0;
	for (int i = 0; i < N; i++) {
		int64_t n = pq.top();
		pq.pop();
		sum += n;
	}

	cout << sum << endl;
}