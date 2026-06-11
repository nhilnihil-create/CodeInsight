#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<double, vector<double>, greater<double> > que;
	for (int n = 0; n < N; ++n) {
		double m;
		cin >> m;
		que.push(m);
	}
	while (1 != que.size()) {
		double d1 = que.top();
		que.pop();
		double d2 = que.top();
		que.pop();
		que.push((d1 + d2) / 2.0);
	}
	double dans = que.top();
	printf("%.10f\n", dans);
	return 0;
}
