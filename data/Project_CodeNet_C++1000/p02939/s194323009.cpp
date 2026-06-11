#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (int) n; i++)
#define all(v) v.begin(), v.end()
#define PB push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const ll INF = 1e9+17;
const ll MOD = 1e9+7;

int dp[200007][2];

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	string s; cin >> s;
	int n = s.size();
	dp[0][0] = 1;
	dp[1][0] = (s[0]==s[1] ? 0 : 2);
	dp[1][1] = (s[0]==s[1] ? 1 : 1);

	for(int i = 2; i < n; i++){
		if(s[i]==s[i-1]){
			dp[i][0] = 1+dp[i-1][1];
			dp[i][1] = 1+max(dp[i-2][0], dp[i-2][1]);
		}else{
			dp[i][0] = 1+max(dp[i-1][0], dp[i-1][1]);
			dp[i][1] = 1+max(dp[i-2][0], dp[i-2][1]);
		}
	}
		
	cout << max(dp[n-1][0], dp[n-1][1]) << '\n';

	return 0;
}