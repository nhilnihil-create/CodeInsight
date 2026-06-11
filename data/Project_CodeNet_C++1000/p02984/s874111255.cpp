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
	rep(i, N)  cin >> A[i];

	for(ll i = 1; i < N; i++) {
		B[i] = (A[i-1] - B[i-1]/2) * 2;
	}

	ll rest = A[N-1] - B[N-1]/2;
	rep(i, N) {
		if(i%2 == 0) {
			cout << B[i] + rest;
		} else {
			cout << B[i] - rest;
		}

		if(i != N - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}

}
