#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];

	int ans;

	long long time = 0;
	int cntb = 1;
	while (cntb <= M) {
		if (time + B[cntb - 1] <= K) {
			time += B[cntb - 1];
			cntb++;
		}
		else break;
	}
	cntb--;
	ans = cntb;

	for (int cnta = 1; cnta <= N; cnta++) {
		time += A[cnta - 1];
		while (time > K && cntb > 0) {
			time -= B[cntb - 1];
			cntb--;
		}
		if (time > K && cntb == 0) break;
		ans = max(ans, cnta + cntb);
	}

	cout << ans << endl;

	return 0;
}