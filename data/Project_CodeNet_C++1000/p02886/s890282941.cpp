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

int N, D[1 << 18], S;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> D[i];
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) S += D[i] * D[j];
	}
	cout << S << endl;
	return 0;
}