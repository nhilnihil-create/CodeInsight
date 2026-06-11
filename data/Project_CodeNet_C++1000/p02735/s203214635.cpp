#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ip pair<ll,ll>
#define ff first
#define ss second
#define MAX 100005
const ll MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int h,w;
	cin>>h>>w;
	string s[h];
	for(int i=0;i<h;i++)
		cin>>s[i];
	
	int dp[h][w];
	if(s[0][0] == '#')
		dp[0][0] = 1;
	else
		dp[0][0] = 0;
	for(int j=1;j<w;j++){
		dp[0][j] = dp[0][j-1];
		if(s[0][j] != s[0][j-1] && s[0][j] == '#')
			++dp[0][j];
	}

	for(int i=1;i<h;i++){
		dp[i][0] = dp[i-1][0];
		if(s[i][0] != s[i-1][0] && s[i][0] == '#')
			++dp[i][0];
		for(int j=1;j<w;j++){
			int v1 = dp[i-1][j], v2 = dp[i][j-1];
			if(s[i-1][j] != s[i][j] && s[i][j] == '#')
				++v1;
			if(s[i][j-1] != s[i][j] && s[i][j] == '#')
				++v2;
			dp[i][j] = min(v1,v2);
		}
	}

	cout<<dp[h-1][w-1]<<endl;
}