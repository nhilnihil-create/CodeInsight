#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

int N;
ll A[200000 + 10], B[200000 + 10];

int bef(int i) {
	if (i == 0)return N - 1;
	else return i - 1;
}

int nxt(int i) {
	if (i == N - 1)return 0;
	else return i + 1;
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++)cin >> B[i];

	queue<int> q;
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		if (B[i] > B[bef(i)] + B[nxt(i)] && B[i] != A[i])q.push(i);
	}
	while (q.size()) {
		int pos = q.front(); q.pop();

		if (((B[pos] - A[pos]) % (B[bef(pos)] + B[nxt(pos)]) == 0)) {
			cnt += ((B[pos] - A[pos]) / (B[bef(pos)] + B[nxt(pos)]));
			B[pos] = A[pos];
		}
		else {
			cnt += B[pos] / (B[bef(pos)] + B[nxt(pos)]);
			B[pos] %= (B[bef(pos)] + B[nxt(pos)]);
			if (A[pos] > B[pos]) {
				cout << -1 << endl;
				return 0;
			}
		}
		if (B[bef(pos)] > B[pos] + B[bef(bef(pos))] && B[bef(pos)] != A[bef(pos)])q.push(bef(pos));
		if (B[nxt(pos)] > B[pos] + B[nxt(nxt(pos))] && B[nxt(pos)] != A[nxt(pos)])q.push(nxt(pos));
	}
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << cnt << endl;
	return 0;
}