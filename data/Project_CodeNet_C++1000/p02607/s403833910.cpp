#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int N, A[1 << 18], cnt;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] % 2 == 1 && i % 2 == 1) cnt++;
	}
	cout << cnt << endl;
	return 0;
}