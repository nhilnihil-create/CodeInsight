#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, M, C[1 << 18];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int num; cin >> num;
		for (int j = 1; j <= num; j++) {
			int e; cin >> e; C[e] = 1;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (C[i] == 0) cnt++;
	}
	cout << cnt << endl;
	return 0;
}