#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N,K;
	cin >> N >> K;
	vector<int>A(N);  
	vector<int>SUM(N + 1);
	long long sum = 0; 
	SUM[0] = 0;
	for (long long n = 0;n<N;++n) {
		cin >> A[n];
		sum += A[n]; 
		SUM[n + 1] = (sum  - (n + 1))%K;
	}
	map<int,int>mp;
	for (int n = 1;n < K;++n) {
		if (n<=N) {
			mp[SUM[n]]++;
		}
	}
	long long ans = 0;
	for (long long n = 0; n <= N; ++n) {
		ans += mp[SUM[n]];
		mp[SUM[n + 1]]--;
		if ((n + K) <= N) {
			mp[SUM[n + K]]++;
		}
	}
	cout << ans <<  endl;
	return 0;
}