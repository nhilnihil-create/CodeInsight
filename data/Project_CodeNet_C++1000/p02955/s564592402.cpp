#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	long long S = 0;
	for (int i = 0; i < N; i++){
		S += A[i];
	}
	vector<long long> f;
	for (int i = 1; (long long) i * i <= S; i++){
		if (S % i == 0){
			f.push_back(i);
			if ((long long) i * i < S){
				f.push_back(S / i);
			}
		}
	}
	long long ans = 0;
	for (long long x : f){
		vector<long long> r(N);
		for (int i = 0; i < N; i++){
			r[i] = A[i] % x;
		}
		sort(r.rbegin(), r.rend());
		long long sum = 0;
		for (int i = 0; i < N; i++){
			sum += r[i];
		}
		long long cnt = 0;
		for (int i = sum / x; i < N; i++){
			cnt += r[i];
		}
		if (cnt <= K){
			ans = max(ans, x);
		}
	}
	cout << ans << endl;
}