#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

bool operater(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		v[i] = p;
	}
	sort(v.begin(), v.end(), operater);

	//for (int i = 0; i < N; i++) {
	//	cout << v[i].first << ' ' << v[i].second << endl;
	//}

	int64_t s = 0;
	bool f = true;

	for (int i = 0; i < N; i++) {
		s += (int64_t)v[i].first;
		if (s > v[i].second) {
			f = false;
			break;
		}
	}

	cout << (f ? "Yes" : "No") << endl;
}