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

int N, L[1 << 18];
int ret = 0;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i];
	sort(L + 1, L + N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (L[i] == L[j] || L[j] == L[k] || L[k] == L[i]) continue;
				if (L[i] + L[j] > L[k]) ret++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}