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

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		pair<int, int> p = { A,i + 1 };
		v[i] = p;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (i) cout << ' ';
		cout << v[i].second;
	}
	cout << endl;
}