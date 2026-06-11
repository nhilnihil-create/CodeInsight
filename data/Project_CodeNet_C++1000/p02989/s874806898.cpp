#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>D(N);
	for (int n = 0;n<N;++n) {
		cin >> D[n];
	}
	sort(D.begin(),D.end());
	cout << D[N/2] -D[N/2-1] << endl;
	return 0;
}
