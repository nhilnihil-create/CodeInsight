#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

#define DIV 1000000007

using namespace std;

long long N;
long long A[300005];

long long modpow(long long ori, long long po){
	long long res = 1;
	while(po > 0){
		if(po&1){
			res *= ori;
			res %= DIV;
		}
		ori *= ori;
		ori %= DIV;
		po >>= 1;
	}
	return res;
}

int main(){
	cin >> N;
	rep(i, N) cin >> A[i];
	reverse(A, A + N);


	long long ans = 0;

	rep(i, 61) {
		//i bit目
		long long zerocount = 0;
		long long onecount = 0;
		rep(j, N) {
			long long num = A[j];

			if((num>>i)&1) {
				ans += zerocount * modpow(2, i);
				ans %= DIV;
			} else {
				ans += onecount * modpow(2, i);
				ans %= DIV;
			}

			if((num>>i)&1) {
				onecount++;
			} else {
				zerocount++;
			}
		}
	}
	cout << ans << endl;
}