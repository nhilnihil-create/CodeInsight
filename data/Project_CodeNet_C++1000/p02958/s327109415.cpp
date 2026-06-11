#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;
ll P[55];

bool check() {
	rep(i, N - 1) {
		if(P[i] > P[i+1]) {
			return false;
		}
	}
	return true;
}

int main(){
	cin >> N;
	rep(i, N) cin >> P[i];

	if(check()) {
		cout << "YES" << endl;
		return 0;
	}

	for(ll i = 0; i < N; i++) {
		for(ll j = i + 1; j < N; j++) {
			swap(P[i], P[j]);
			if(check()) {
				cout << "YES" << endl;
				return 0;
			}
			swap(P[i], P[j]);
		}
	}
	cout << "NO" << endl;
}