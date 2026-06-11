#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

constexpr ll mod = 1000000007LL;

ll solve(int S){
	if (S == 0) return 1;
	if (S <= 2) return 0;
	static map<int, ll> memo;
	if (memo[S]) return memo[S];
	ll ret = 0;
	for (int i = 3; i <= S; ++i)
		ret = (ret + solve(S - i)) % mod;
	return memo[S] = ret;
}

int main(void){
	int S; cin >> S;
	cout << solve(S) << endl;
	return 0;
}