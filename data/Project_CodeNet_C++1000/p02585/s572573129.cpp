#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long calc(vector<long long>& List, int K) {
	int N = List.size();
	vector<long long> LSum(N);
	LSum[0] = List[0];
	for (int i = 1; i < N; i++) LSum[i] = LSum[i - 1] + List[i];

	int NK = K;
	if (K > N) K = N;

	long long MAX = -pow(10ll, 10);
	for (int i = 0; i < K; i++) MAX = max(MAX, LSum[i] + max(0ll, LSum[N - 1] * ((NK - (i + 1)) / K)));
	for (int i = 1; i < N; i++) {
		for (int j = i; j < i + K; j++) {
			int nj = j % N;
			if (i <= nj) MAX = max(MAX, LSum[nj] - LSum[i - 1] + max(0ll, LSum[N - 1] * ((NK - (j - i + 1)) / K)));
			else MAX = max(MAX, LSum[N - 1] - LSum[i - 1] + LSum[nj] + max(0ll, LSum[N - 1] * ((NK - (j - i + 1)) / K)));
		}
	}
	return MAX;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> P(N);
	vector<long long>C(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		P[i]--;
	}
	for (int i = 0; i < N; i++) cin >> C[i];
	vector<int> Used(N, 0);
	long long ans = -pow(10ll, 10);
	for (int st = 0; st < N;) {
		Used[st] = 1;
		vector<long long> List;
		List.push_back(C[st]);
		int now = P[st];
		while (now != st) {
			List.push_back(C[now]);
			Used[now] = 1;
			now = P[now];
		}
		ans = max(calc(List, K), ans);
		while (st < N && Used[st]) st++;
	}
	cout << ans << endl;
}
