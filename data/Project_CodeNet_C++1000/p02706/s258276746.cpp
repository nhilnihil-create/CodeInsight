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

long long N, M, A[1 << 18];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i];
		N -= A[i];
	}
	if (N < 0) cout << "-1" << endl;
	else cout << N << endl;
	return 0;
}