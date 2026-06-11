#include "bits/stdc++.h"
using namespace std;
const long long INF = (long long)(1e18) + 1;
int main() {
	int N,K;
	cin >> N >> K;
	vector<int>P(N);
	for (int n = 0;n<N;++n) {
		cin >> P[n]; 
		P[n]++;
	}
	int ans = 0;
	int tmp = 0;
	for (int n = 0;n<K;++n) {
		tmp += P[n];
	}
	ans = tmp;
	for (int n = 1;n <= N - K;++n) {
		tmp = tmp - P[n - 1] + P[n - 1 + K];
		ans = max(tmp, ans);
	}
	double dans = ans;
	dans /= 2;
	printf("%.10f\n", dans);
	//cout << (ans)/2.0<<endl;
	return 0;
}