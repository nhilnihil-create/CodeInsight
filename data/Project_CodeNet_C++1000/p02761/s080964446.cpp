#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

bool check(int a, int s, int c) {
	for (int ss = 1; ss < s; ss++) a /= 10;
	return a % 10 == c;
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> s(M), c(M);
	for (int i = 0; i < M; i++) {
		cin >> s[i] >> c[i];
	}

	int minA[4] = { 0, 0, 10, 100 };
	int maxA[4] = { 0, 9, 99, 999 };
	for (int a = minA[N]; a <= maxA[N]; a++) {
		bool ok = true;
		for (int i = 0; i < M; i++) {
			if (!check(a, N-s[i]+1, c[i])) {
				ok = false;
					break;
			}
		}
		if (ok) {
			print(a);
			return 0;
		}
	}

	print(-1);
	return 0;
}

