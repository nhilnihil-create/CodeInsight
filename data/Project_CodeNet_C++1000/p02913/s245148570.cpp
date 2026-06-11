#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
inline int ri() {
	int r; cin >> r; return r;
}


int main()
{
	int n = ri();
	string s;
	cin >> s;
	vector<vector<bool>> dp(n + 1, vector<bool>(n + 1)); 
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {

			int len = 0, ir = i, jr = j;
			while(s[ir] == s[jr] && ir < j && jr < n && !dp[ir][jr]) {
				dp[ir][jr] = true;
				ir++, jr++, len++;
			}
          
			ans = max(ans, len);
		}
	}
	cout << ans << endl;
}