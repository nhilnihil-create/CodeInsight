#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	string S;
	cin >> S;
	vector<int> A(2 * N + 1);
	vector<int> X(2 * N);
	S.insert(S.begin(), 'W');
	S.push_back('W');
	for (int i = 0; i < 2 * N + 1; i++) {
		if (S[i] == S[i + 1]) {
			A[i] = 0;
		}
		else {
			A[i] = 1;
		}
	//	cerr << A[i] << endl;
	}
	//cerr << endl;

	for (int i = 0; i < 2 * N; i++) {
		if (A[i] == 1) {
			X[i] = 1;
		}
		else {
			A[i + 1] ^= 1;
			X[i] = -1;
		}
		//cerr << X[i] << endl;
	}
	int res = 0;
	if (A.back() == 1) {
		res = 0;
	}
	else {
		int cnt = 0;
		res = 1;
		for (int i = 0; i < 2 * N; i++) {
			if (X[i] == 1) {
				cnt++;
			}
			else {
				res = (res * cnt) % MOD;
				cnt--;
			}
		}
		for (int i = 1; i <= N; i++) {
			res = (res * i) % MOD;
		}
		if (cnt != 0)res = 0;
	}
	
	cout << res << endl;
}