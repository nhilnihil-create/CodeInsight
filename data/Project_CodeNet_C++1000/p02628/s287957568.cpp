#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> p(N);
	vector<int> q(K);
	for (int i = 0; i < N; i++) {
		cin >> p.at(i);
	}
	for (int i = 0; i < K; i++) {
		q.at(i) = p.at(0);
		for (int j = 0; j < (N - 1); j++) {
			if (q.at(i) >= p.at(j + 1)) {
				q.at(i) = p.at(j + 1);
			}
		}
		for (int j = 0; j < N; j++) {
			if (q.at(i) == p.at(j)) {
				p.at(j) = 2000;
				break;
			}
		}
	}
	int sum(int, vector<int>);
	printf("%d", sum(K, q));
}

int sum(int K, vector<int> q) {
	int Buffer = 0;
	for (int i = 0; i < K; i++) {
		Buffer += q.at(i);
	}
	return Buffer;
}