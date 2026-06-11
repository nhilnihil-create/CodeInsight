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

	vector<int> p(N);
	for (int i = 0; i < N; i++) cin >> p[i];

	auto v = p;
	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (p[i] != v[i]) cnt++;
	}

	if (cnt == 2) cout << "YES" << endl;
	else if (cnt == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}