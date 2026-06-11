#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, K;
	cin >> N >> K;
	// 辺1に辺[2..N]をつなげる(スターグラフにする)
	// この状態で, (N-1)(N-2)/2個の最短距離2の頂点対ができる
	// [2..N]のうち繋がっていない頂点対を(N-1)(N-2)/2 - K(個)繋げる
	// ちなみに, K > (N-1)(N-2)/2 のときは無理
	if(K > (N - 1) * (N - 2) / 2) {
		cout << -1 << endl;
		return 0;
	}

	cout << (N - 1) + (N - 1) * (N - 2) / 2 - K << endl;
	for(int i=2;i<=N;i++) {
		cout << 1 << " " << i << endl;
	}
	int left = 2, right = 3;
	for(int i=0;i<(N-1)*(N-2)/2-K;i++) {
		cout << left << " " << right << endl;
		right++;
		if(right == N + 1) {
			left++;
			right = left + 1;
		}
	}
	return 0;
}