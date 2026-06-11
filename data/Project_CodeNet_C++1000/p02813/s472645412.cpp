#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	map<int, int> mp;
	mp[1] = 1;
	for (int i = 2; i < 10; ++i) {
		mp[i] = mp[i - 1] * i;
	}

	int N;
	cin >> N;

	vector<int> P(N);
	vector<int> Q(N);
	for (int i = 0; i < N; ++i)cin >> P[i];
	for (int i = 0; i < N; ++i)cin >> Q[i];

	int p = 0;
	int q = 0;
	for (int i = N; 0 < i; --i) {
		int count = 0;
		for (size_t t = (N - i) + 1; t < P.size(); ++t) {
			if (P[t] < P[N - i])++count;
		}

		p += mp[i - 1] * count;

		count = 0;
		for (size_t t = (N - i) + 1; t < Q.size(); ++t) {
			if (Q[t] < Q[N - i])++count;
		}

		q += mp[i - 1] * count;
	}

	cout << abs(p - q) << endl;
	return 0;
}