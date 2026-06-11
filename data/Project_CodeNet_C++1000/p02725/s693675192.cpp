#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;

int main() {
	int K, N;
	cin >> K >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	int M = K - A[N - 1]+A[0];
	int ans = 0;
	bool dis = false;
	for (int i = 0; i < N - 1; i++) {
		int d = A[i + 1] - A[i];
		ans += d;
		if (M < d) {
			M = d;
			dis = true;
		}
	}
		if (dis) {
			cout << ans - M + K - A[N - 1]+A[0] << endl;
		}
		else {
			cout << ans << endl;
		}
}
