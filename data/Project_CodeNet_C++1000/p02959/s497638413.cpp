#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;
ll A[100005];
ll B[100005];

int main(){
	cin >> N;
	rep(i, N + 1) cin >> A[i];
	rep(i, N) cin >> B[i];


	ll ans = 0;
	rep(i, N) {
		if(A[i] >= B[i]) {
			ans += B[i];
		} else {
			ans += A[i];
			B[i] -= A[i];
			ll rem = min(B[i], A[i+1]);
			ans += rem;
			A[i+1] -= rem;
		}
	}
	cout << ans << endl;


}

