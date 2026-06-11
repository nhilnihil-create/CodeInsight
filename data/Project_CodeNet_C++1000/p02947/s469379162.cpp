#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;

int main(){
	map<string, ll> memo;
	cin >> N;

	ll ans = 0;
	rep(i, N) {
		string S;
		cin >> S;
		sort(S.begin(), S.end());
		ans += memo[S];
		memo[S]++;
	}
	cout << ans << endl;
}
