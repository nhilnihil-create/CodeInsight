#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	cin >> N;

	vector<ll> A(N), B(N), C(N);

	rep(i, N) {
		cin >> A[i];
		A[i]--;
	}
	rep(i, N) cin >> B[i];
	rep(i, N-1) cin >> C[i];

	ll ans = 0;
	rep(i, N) {
		ans += B[A[i]];
		if(i != N - 1 && A[i] + 1 == A[i+1]) {
			ans += C[A[i]];
		}
	}
	cout << ans << endl;


}
