#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, K;
string S;

int main(){
	cin >> N >> K >> S;
	if(N == 1) {
		cout << 0 << endl;
		return 0;
	}

	ll num = 0;
	char ch = 'x';
	rep(i, N) {
		if(ch != S[i]) {
			num++;
			ch = S[i];
		}
	}

	char left, right;
	left  = S[0];
	right = S[N-1];

	if(left == right) {
		ll mid = num/2;
		mid = max(0ll, mid - K);
		cout << N - 1 - 2 * mid << endl;
	} else {
		ll mid = num/2;
		mid = max(0ll, mid - K);
		if(mid == 0) {
			cout << N - 1 << endl;
			return 0;
		}
		ll ans = N - 1;
		ans--;
		mid--;
		cout << ans - 2 * mid << endl;
	}
}