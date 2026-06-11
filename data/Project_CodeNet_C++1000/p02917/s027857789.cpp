#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	ll ans = 0;
	cin >> N;
	vector<ll> B(N);
	rep(i, N-1) cin >> B[i];

	ans += B[0];
	for(long long i = 0; i < N-2; i++) {
		ans += min(B[i], B[i+1]);
	}
	ans += B[N-2];

	cout << ans << endl;

}

