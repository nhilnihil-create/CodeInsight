#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>X(N);
	vector<int>Y(N);
	for (int n = 0;n<N;++n) {
		cin >> X[n] >> Y[n];
	}
	double ans = 0;
	for (int n = 0;n<N;++n) {
		for (int m = n + 1;m<N;++m) {
			ans += 2.0 * sqrt((X[n]-X[m])*(X[n]-X[m])+(Y[n]-Y[m])*(Y[n]-Y[m])) / N;
		}
	}
	printf("%.10f\n", ans);
	return 0;
}
