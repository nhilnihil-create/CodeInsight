#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

long long N, K, C, cl[1000009], cr[1000009];
string S;

int calc(int pos) {
	int pl = pos - (C + 1); pl = max(pl, 0);
	int pr = pos + (C + 1); pr = min(pr, (int)N + 1);
	return cl[pl] + cr[pr];
}

bool solve(int pos) {
	int T1 = calc(pos);
	int T2 = 0;
	for (int i = pos - C; i <= pos + C; i++) {
		if (i <= 0 || i > N || i == pos || S[i - 1] == 'x') continue;
		T2 = max(T2, calc(i) + 1);
	}
	if (max(T1, T2) < K) return true;
	return false;
}

int main() {
	cin >> N >> K >> C >> S;

	vector<int> vec; int pres = -(1 << 30);
	for (int i = 1; i <= N; i++) {
		if (S[i - 1] == 'o' && i - pres > C) { vec.push_back(i); pres = i; }
	}

	vector<int> vec2; int pre2 = (1 << 30);
	for (int i = N; i >= 1; i--) {
		if (S[i - 1] == 'o' && pre2 - i > C) { vec2.push_back(i); pre2 = i; }
	}

	for (int i : vec) cl[i] = 1;
	for (int i : vec2) cr[i] = 1;
	for (int i = 1; i <= N; i++) cl[i] += cl[i - 1];
	for (int i = N; i >= 1; i--) cr[i] += cr[i + 1];

	vector<int> ans;
	for (int i : vec) {
		if (solve(i) == true) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	return 0;
}