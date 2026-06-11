#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pll = pair < ll, ll >;
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
 
#define pb push_back
#define mp make_pair
#define fastIo() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
const int MOD = 1e9 + 7, INF = INT_MAX, N = 1e6 + 10;

const int m = 2019;

int main(){ 
	string s; cin >> s;
	int n = s.size();
	int dp[n+1];
	fill(dp, dp + n + 1, 0);
	int mul = 1, ans = 0;
	int cnt[2019];
	fill(cnt, cnt + 2019, 0);
	cnt[0] = 1;
	for(int i = n - 1; i >= 0; i--) {
		dp[i] = (dp[i+1] + ((s[i] - '0') * mul % m)) % m;
		mul *= 10;
		mul %= m;
		ans += cnt[dp[i]];
		cnt[dp[i]]++;
		// cout << mul << endl;
	}
	cout << ans << endl;
}
