#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,K;
	cin >>N >>K;
	int ans = 0;
	vector<int>D(N);
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		if (num >= K) {
			++ans;
		}
	}
	cout << ans <<endl;
	return 0;
}