#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	cin >> N;
	vector<ll> A(N);

	rep(i, N) cin >> A[i];

	ll maxi = -1;
	ll maxi2 = -1;

	rep(i, N) {
		if(maxi < A[i]) {
			maxi2 = maxi;
			maxi = A[i];
		} else if (maxi2 < A[i]) {
			maxi2 = A[i];
		}
	}

	rep(i, N) {
		if(A[i] == maxi) {
			cout << maxi2 << endl;
		} else {
			cout << maxi << endl;
		}
	}
}
