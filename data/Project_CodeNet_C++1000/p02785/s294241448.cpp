#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N, K, H;
	cin >> N >> K;
	vector<int> vec(N);
	long long total = 0;
	for (int i = 0; i < N; i++) {
		cin >> H;
		vec.at(i) = H;
	}
	sort(vec.begin(),vec.end());
	if (vec.size() <= K) {
		cout << 0 << endl;
	}
	else {
		for (int j = 0; j < N - K; j++) {
			total += vec.at(j);
		}
		cout << total << endl;
	}
}