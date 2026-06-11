#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;

int main() {
	int N, L; cin >> N >> L;
	int min = INF;
	int sum = 0;
	rep(i, N) {
		int num = L + i;
		if (abs(min) > abs(num))min = num;
		sum += num;
	}
	cout << sum - min;
}