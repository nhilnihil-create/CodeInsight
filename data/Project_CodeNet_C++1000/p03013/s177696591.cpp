#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, M;
set<ll> A;
ll dp[100005];

int main(){
	cin >> N >> M;
	rep(i, M) {
		ll tmp;
		cin >> tmp;
		A.insert(tmp);
	}

	dp[0] = 1;

	rep(i, N + 1) {
		if(A.count(i + 1) == 0) {
			dp[i+1] += dp[i];
dp[i+1] %= DIV;
		}
		if(A.count(i + 2) == 0) {
			dp[i+2] += dp[i];
dp[i+2] %= DIV;
		}
	}
	cout << dp[N] << endl;
}

