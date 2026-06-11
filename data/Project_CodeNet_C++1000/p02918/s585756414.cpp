#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, K;
	string S;
	cin >> N >> K >> S;

	int c = 0;
	for (int i = 1; i < N; i++) {
		if (S[i] != S[i - 1]) c++;
	}

	cout << N - 1 - max(0, c - 2 * K) << endl;
}