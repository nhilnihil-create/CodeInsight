#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long N, A[200009], B[200009], cnt;
queue<int>Q;

bool check(int pos) {
	int id1 = (pos + N - 1) % N, id2 = (pos + 1) % N;
	if (B[pos] - B[id1] - B[id2] >= A[pos]) return true;
	return false;
}

void sousa(int pos) {
	int id1 = (pos + N - 1) % N, id2 = (pos + 1) % N;
	long long rem = B[pos] - A[pos], rem2 = B[id1] + B[id2];
	long long K = rem / rem2;
	B[pos] -= B[id1] * K;
	B[pos] -= B[id2] * K;
	cnt += K;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	for (int i = 0; i < N; i++) {
		if (check(i) == true) Q.push(i);
	}

	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		sousa(pos);

		for (int i = -1; i <= 1; i++) {
			int v = (pos + N + i) % N;
			if (check(v) == true) Q.push(v);
		}
	}
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) cnt = -1;
	}
	cout << cnt << endl;
	return 0;
}