#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, K;
long long P[1 << 18];
long long C[1 << 18];

long long solve(int pos) {
	vector<long long> vec; int cx = pos;
	while (true) {
		vec.push_back(C[cx]);
		cx = P[cx];
		if (cx == pos) break;
	}

	long long sum = 0;
	for (int i = 0; i < vec.size(); i++) sum += vec[i];

	long long maxn = -(1LL << 60), ret = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (i + 1 > K) continue;
		ret += vec[i];
		if (sum < 0) maxn = max(maxn, ret);
		else {
			long long rem = (K - (i + 1)) / (long long)vec.size();
			maxn = max(maxn, rem * sum + ret);
		}
	}
	return maxn;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) cin >> C[i];

	long long Answer = -(1LL << 60);
	for (int i = 1; i <= N; i++) Answer = max(Answer, solve(i));
	cout << Answer << endl;
	return 0;
}