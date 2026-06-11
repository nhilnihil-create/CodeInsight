#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846264338327950L

int main(void) {

	long long n, tmp;
	map<long long, long long> A;
	long long ans = 0;
	map<long long, long long> max_bottomup, max_topdown, min_bottomup, min_topdown, max_node;

	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> tmp;
		A[i] = tmp;
	}

	for (int i = n; i >= 0; i--) {
		max_bottomup[i] = max_bottomup[i + 1] + A[i];
		min_bottomup[i] = (min_bottomup[i+1] + 1) / 2 + A[i];
	}

	if (min_bottomup[0] > 1 || max_bottomup[0] < 1) {
		cout << -1 << endl;
		return 0;
	}


	max_topdown[0] = 1;
	for (int i = 1; i <= n; i++) {
		max_topdown[i] = min((max_topdown[i - 1]-A[i-1]) * 2, max_bottomup[i]);
	}

	for (int i = 0; i <= n; i++) {
		ans = ans + max_topdown[i];
	}



	cout << ans << endl;



	return 0;
}

