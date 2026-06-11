#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	if(n == 1){
		cout << k/2 << endl;
		return 0;
	}
	if(k < 4){
		string s2 = "";
		rep(i,k){
			s2 += s;
		}
		ll ans = 0;
		for(int i = 1; i < s2.size(); ){
			if(s2[i-1] != s2[i]) ++i;
			else{
				++ans;
				i += 2;
			}
		}
		cout << ans << endl;
		return 0;
	}
	int src = 1;
	vector<ll> dp(2, -1);
	vector<int> memo;
	rep(loop,4){
		int lst = 0;
		bool f = false;
		if(dp[src] == -1){
			dp[src] = 0;
			f = true;
		}
		for(int i = src; i < n; ){
			if(s[(i+n-1)%n] != s[i]) ++i;
			else{
				if(f) dp[src]++;
				lst = i;
				i += 2;
			}
		}
		memo.push_back(src);
		src = (lst == n-1);
	}
	if(memo[2] == 0){
		cout << dp[1] + dp[0] * (k-1) << endl;
	}
	else{
		ll ans = 0, sum = 0;
		rep(i,4){
			sum += dp[memo[i]];
		}
		ans += sum * (k/4);
		rep(i,k%4){
			ans += dp[memo[i]];
		}
		cout << ans << endl;
	}
	return 0;
}
