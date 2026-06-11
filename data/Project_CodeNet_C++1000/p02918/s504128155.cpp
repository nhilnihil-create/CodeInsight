#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;

int main() {
	int N, K; cin >> N >> K;
	string S; cin >> S;

	int count = 1;
	char preCh = S[0];
	rep(i, N) {
		if (preCh != S[i])count++;
		preCh = S[i];
	}
	//cout << count;
	count = max(1, count - 2 * K);
	cout << N - count;
}