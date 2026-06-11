#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N, K;

int main(){
	cin >> N >> K;
	vector<long long>A(N);
	vector<long long>F(N);
	rep(i, N) cin >> A[i];
	rep(i, N) cin >> F[i];


	sort(A.begin(), A.end());
	sort(F.begin(), F.end(), greater<long long>());

	long long start = -1;
	long long end = 1e12 + 1;

	while(start + 1 < end) {
		long long mid = (start + end)/2;

		long long cost = 0;
		rep(i, N) {
			long long minia;
				minia = mid/F[i];
			//if(mid%F[i] == 0) {
			//	minia = mid/F[i];
			//} else {
			//	minia = mid/F[i] + 1;
			//}
			cost += max(A[i] - minia, 0LL);
		}
		
		if(cost > K) {
			start = mid;
		} else {
			end = mid;
		}
	}


	cout << end << endl;
}