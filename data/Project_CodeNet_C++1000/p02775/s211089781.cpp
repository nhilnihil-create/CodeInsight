#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = 1<<30;
const ll MOD = 1e9+7;

int main(){
	string s;
	vector<int> dp[2];

	cin>>s;

	int n = s.size();
	dp[0].assign(n+1, 0);
	dp[1].assign(n+1, 0);

	for(int i=n-1;i>=0;i--){
		dp[0][i] = min(s[i]-'0'+dp[0][i+1], 1+10-(s[i]-'0')+dp[1][i+1]);
		dp[1][i] = min(-1+10-(s[i]-'0')+dp[1][i+1], s[i]-'0'+dp[0][i+1]);
	}

	cout<<dp[0][0]<<"\n";

	return 0;
}

/*

93
100-10

53

*/