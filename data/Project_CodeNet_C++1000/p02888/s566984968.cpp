#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	int MAX = 2 * 1e3 + 1;
	vector<int64_t> L(N), C(MAX);
	for (int i = 0; i < N; i++) {
		int64_t n;
		cin >> n;
		C[n]++;
		L[i] = n;
	}
	for (int i = 1; i < MAX; i++) C[i] += C[i - 1];

	//for (int i = 0; i < 10; i++) {
	//	if (i) cout << ' ';
	//	cout << C[i];
	//}

	int64_t ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			int64_t left, right;
			left = abs(L[i] - L[j]);
			right = L[i] + L[j];

			int64_t a = C[right - 1] - C[left];
			if (L[i] > left && L[i] < right) a--;
			if (L[j] > left && L[j] < right) a--;
			ret += max(a, (int64_t)0);
		}
	}

	cout << ret / 6 << endl;
}