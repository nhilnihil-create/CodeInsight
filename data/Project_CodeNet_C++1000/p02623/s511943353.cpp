#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <cmath>
//#include <iomanip>
//#include <map>
//#include <unordered_map>
//#include <cstring>
#include <queue>

using namespace std;
using ll = long long;
// using pint = pair<int, int>;
// ll INF = 1LL << 60;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	vector<ll> a(N + 1), b(M + 1);
	a[0] = 0;
	b[0] = 0;
	for (int i = 0; i < N; i++) {
		a[i + 1] = a[i] + A[i];
	}
	for (int i = 0; i < M; i++) {
		b[i + 1] = b[i] + B[i];
	}
	int ans = 0, j = M;
	for (int i = 0; i < N + 1; i++) {
		if (a[i] > K) break;
		while (b[j] > K - a[i]) j--;
		ans = max(ans, i + j);
	}
	cout << ans << endl;
	return 0;
}