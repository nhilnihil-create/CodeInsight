#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll rmemo[100005];
ll lmemo[100005];
ll ans[100005];

int main(){
	string S;
	cin >> S;

	ll num = 0;
	rep(i, S.size() - 1) {
		if(S[i] == 'R') {
			num++;
		} else {
			num = 0;
		}
		if(S[i+1] == 'L') {
			rmemo[i] = num;
		}
	}

	num = 0;
	for(ll i = S.size() - 1; i > 0; i--) {
		if(S[i] == 'L') {
			num++;
		} else {
			num = 0;
		}
		if(S[i-1] == 'R') {
			lmemo[i] = num;
		}
	}

	rep(i, S.size()) {
		if(rmemo[i]) {
			ll odd, even;
			even = rmemo[i] / 2;
			odd = rmemo[i] / 2;
			if(rmemo[i] % 2 == 1) even++;
			ans[i] += even;
			ans[i+1] += odd;

		}
	}

	rep(i, S.size()) {
		if(lmemo[i]) {
			ll odd, even;
			even = lmemo[i] / 2;
			odd = lmemo[i] / 2;
			if(lmemo[i] % 2 == 1) even++;
			ans[i] += even;
			ans[i-1] += odd;

		}
	}

	rep(i, S.size()) {
		cout << ans[i];
		if(i != S.size() - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}



}