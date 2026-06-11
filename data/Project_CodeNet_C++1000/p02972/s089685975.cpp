#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18];
vector<int> E[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) E[j].push_back(i);
	}

	vector<int> vec;
	for (int i = N; i >= 1; i--) {
		if (A[i] == 0) continue;
		for (int j : E[i]) A[j] ^= 1;
		vec.push_back(i);
	}
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		if (i) cout << " "; cout << vec[i];
	}
	cout << endl;
	return 0;
}