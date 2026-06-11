#include "bits/stdc++.h"
using namespace std;
const int K = 43;

long long calc(long long N) {
	vector<long long> x;
	for (long long i = 2; i*i <= N; i++) {
		int m = 0;
		while (N%i == 0) { // 素数で割り切れなくなるまで割っていく
			m++;//割った個数を配列に足す
			N /= i;
		}
		if (0 != m) {
			x.push_back(m);
		}
		if (1 == N) {
			break;
		}
	}
	if (1 != N) {
		x.push_back(1);
	}

	long long nAns = 1;
	for (long long n = 0; n < x.size(); ++n) {
		nAns *= x[n] + 1;
	}
	return nAns;
}

long long calc2(long long N) {
	long long nAns = 0;
	for (long long i = 2; i <= sqrt(N); i++) {
		if (0 == N % i) {
			{
				long long tmpN = N;
				while (tmpN%i == 0) {
					tmpN /= i;
				}
				if (1 == tmpN % i) {
					nAns++;
				}
			}
			{			
				long long tmpN = N;
				long long isub = N / i;
				if (isub == i) {
					continue;
				}
				while (tmpN%isub == 0) {
					tmpN /= isub;
				}
				if (1 == tmpN % isub) {
					nAns++;
				}
			}
		}
	}
	return nAns + 1;
}


int main() {
	long long N;
	cin >> N;
	int n = 0;
	//case1
	// N = 1+ nk を満たす２以上のもの
	long long ans1 = calc(N - 1) - 1;
	//case2
	// N = (k+1)*k^n
	long long ans2 = calc2(N);
	cout << ans1+ans2<<  endl;
	return 0;
}


