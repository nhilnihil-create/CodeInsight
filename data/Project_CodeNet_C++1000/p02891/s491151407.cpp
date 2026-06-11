#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define int ll

const int N = 110;

int k, dp[N];

int solve(string s){
	int n = s.size();
	for(int i=0 ; i<n ; i++){
		int cur = 1e9;
		for(int j=i-1 ; j>0 ; j--){
			if(s[j] == s[j-1]){
				cur = min(cur, dp[j]);
				cur = min(cur, dp[j-1]);
				break;
			}
		}
		if(cur>n)
			cur = 0;
		dp[i] = 1 + cur;
	}
	int ret=0, all=0;
	for(int i=n-1 ; i>0 ; i--)
		if(s[i] == s[i-1]){
			all = min(dp[i-1], dp[i]);
			break;
		}
	if(s[0] != s[n-1])
		return all*k;
	return dp[n-1]*(k-1) + all;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;cin >> s;
	cin >> k;
	bool f = true;
	for(auto c : s)
		f &= (c == s[0]);
	if(f){
		cout << k*s.size()/2 << "\n";
		return 0;
	}
	string t = s;
	reverse(t.begin(), t.end());
	cout << min(solve(s), solve(t)) << "\n";
}























