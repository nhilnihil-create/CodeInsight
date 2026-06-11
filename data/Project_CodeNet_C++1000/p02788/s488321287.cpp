#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, D, A;
	cin >> N >> D >> A;
	vector<pair<int,int>>X;
	for (int n = 0;n<N;++n) {
		int x, h;
		cin >> x >> h; 
		int att = 0;
		att = h / A;
		if (0 != h%A) {
			att++;
		}
		X.push_back(make_pair(x, att));
	}
	sort(X.begin(), X.end()); 
	vector<int>Y(N);//巻き込みkill
	for (int n = 0; n < N; ++n) {
		int num = X[n].first + 2 * D;
		int tmp;
		if (0 == n) {
			tmp = 0;
		}
		else {
			tmp = Y[n - 1];
		}
		for (int m = tmp;m < N ;++m) {
			if (num < X[m].first) {
				Y[n] = m - 1;
				break;
			}
			if (m == N-1) {
				Y[n] = m;
			}
		}
	}
	vector<int>R(N + 100);//累積和
	long long sum = 0;
	//左から、貪欲に最適に殺していく
	long long ans = 0;
	for (int n = 0; n < N; ++n) {
		sum += R[n]; 
		if (X[n].second > sum) {
			R[n + 1] += X[n].second - sum; 
			R[Y[n] + 1] -= X[n].second - sum; 
			ans += (long long)(X[n].second - sum);
		}
	}
	cout << ans <<  endl;
	return 0;
}