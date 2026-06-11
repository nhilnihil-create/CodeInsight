#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

string S;
long long K;

long long solve(string V) {
	vector<int> R; int cnt = 0;
	for (int i = 0; i < V.size(); i++) {
		cnt += 1;
		if (i + 1 == V.size() || V[i] != V[i + 1]) {
			R.push_back(cnt); cnt = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < R.size(); i++) ans += R[i] / 2;
	return ans;
}

int main() {
	cin >> S >> K;
	
	string S1 = S;
	string S2 = S + S;
	long long A1 = solve(S1);
	long long A2 = solve(S2);

	bool flag = false;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != S[(i + 1) % S.size()]) flag = true;
	}
	if (flag == true) {
		cout << A1 + (A2 - A1) * (K - 1LL) << endl;
	}
	else {
		cout << 1LL * (long long)S.size() * K / 2LL << endl;
	}
	return 0;
}