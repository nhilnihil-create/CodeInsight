#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N)cin >> a[i];

	vector<int> box(N, 0);
	rep(i, N) {
		int num = N / (N - i);
		int total = 0;
		rep(j, num - 1)total += box[(j + 2) * (N - i) - 1];
		if (total % 2 == 0) {
			if (a[N - i - 1] == 0)box[N - i - 1] = 0;
			else box[N - i - 1] = 1;
		}
		else {
			if (a[N - i - 1] == 0)box[N - i - 1] = 1;
			else box[N - i - 1] = 0;
		}
	}
	int M = accumulate(box.begin(), box.end(), 0);
	if (M%2==a[0]) {
		cout << M << endl;
		rep(i, N) {
			if (box[i] == 1)cout << i + 1 << " ";
			}
		}
	else cout << -1;
}