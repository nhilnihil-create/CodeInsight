#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#include <cmath>
#define ll long long

using namespace std;

const double pi = 3.14159265358979323846;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int N, K, d;

	cin >> N >> K;

	vector<vector<int>> g(N + 1);

	for (int i = 0; i < K; i++) {

		cin >> d;

		vector<int> a(d + 1);

		for (int j = 1; j <= d; j++) {
			cin >> a[j];
			g[a[j]].push_back(j);
		}
	}

	int num = 0;

	for (int x = 1; x <= N; x++) {
		if (g[x].empty()) {
			num++;
		}
	}


	cout << num << endl;
	return 0;
}