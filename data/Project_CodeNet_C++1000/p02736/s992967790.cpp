#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

// combination(a,b)が奇数か判定
bool comb(int a, int b) {
	int dis = a - b;
	ll cnt0 = 0;
	while (a) {
		cnt0 += a / 2; a >>= 1;
	}
	ll cnt1 = 0;
	while (b) {
		cnt1 += b / 2; b >>= 1;
	}
	while (dis) {
		cnt1 += dis / 2; dis >>= 1;
	}
	return cnt0 <= cnt1;
}

int solve(string a) {
	int N = a.length();
	if (N == 2) {
		return abs((a[0] - '0') - (a[1] - '0'));
	}
	// 答えが1かどうか判定する
	int f = 0;
	for (int i = 0; i < N; ++i)
		if (comb(N - 1, i))
			f ^= (a[i] == '1' ? 1 : 0);
	if (f) return 1;
	// 答えが2かどうか判定する
	for (int i = 0; i < N; ++i)
		if (a[i] == '1')
			return 0;
	for (int i = 0; i < N; ++i) {
		a[i] = (a[i] == '2' ? '1' : '0');
	}
	f = 0;
	for (int i = 0; i < N; ++i)
		if (comb(N - 1, i))
			f ^= (a[i] == '1' ? 1 : 0);
	if (f) return 2;
	return 0;
}

int main() {
	int N; cin >> N;
	string a; cin >> a;
	for (int i = 0; i < N; ++i)
		a[i] = (char)(a[i] - 1);
	cout << solve(a) << endl;
	return 0;
}