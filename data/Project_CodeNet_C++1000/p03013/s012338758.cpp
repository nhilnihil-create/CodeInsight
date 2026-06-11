#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M;
	cin >> N >> M;

	vector<bool> br(N);
	vector<int64_t> v(N);

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		br[n - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		if (br[i]) continue;
		if (i == 0) v[i] = 1;
		else if (i == 1) v[i] = v[i - 1] + 1;
		else {
			v[i] = v[i - 1] + v[i - 2];
			v[i] %= MOD;
		}
	}

	//for (int i = 0; i < N; i++) cout << v[i] << ' ';
	//cout << endl;

	cout << v[N - 1] << endl;
}