#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N, D;
ll X[30][30];


bool check(ll i, ll j) {
	ll sum = 0;
	rep(k, D) {
		sum += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
	}

	ll s = sqrt(sum);

	return (s * s == sum) || ((s+1) * (s+1) == sum) || ((s-1) * (s-1) == sum);
}


int main(){

	cin >> N >> D;
	rep(i, N) rep(j, D) cin >> X[i][j];


	ll ans = 0;
	for(ll i = 0; i < N; i++) {
		for(ll j = i + 1; j < N; j++) {
			if(check(i, j)) ans++;
		}
	}
	cout << ans << endl;

}