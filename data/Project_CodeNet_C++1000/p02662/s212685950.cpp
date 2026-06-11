#include <bits/stdc++.h>

#define FOR(i,a,b) for(auto i = a; i < b; i++)
#define FORD(i,a,b) for(auto i = a-1; i >= b; i--)
#define FORS(i,a,b,s) for(auto i = a; i < b; i+=s)

using namespace std;

typedef long long ll;

#define MOD 998244353

int N, S;
vector<int> a;
ll dp[3001][3001];
ll pow2[3001];
ll solve(int n, int s){
	if(s == S)return pow2[N-n];
	if(s > S)return 0;
	if(n>=N)return 0;
	if(dp[n][s]!=-1)return dp[n][s];
	ll ret = (solve(n+1,s+a[n])+2*solve(n+1,s))% MOD;

	dp[n][s] = ret;
	return ret;
}


int main(){
    /* ifstream cin("in.txt"); */
	
	pow2[0] = 1;
	FOR(i,1,3001)pow2[i] = pow2[i-1]*2 % MOD;

	memset(dp,-1,sizeof(dp));
	cin >> N >> S;
	a = vector<int>(N);
	FOR(i,0,N){
		cin >> a[i];
	}
	
	cout << solve(0,0) << endl;;

	return 0;
}
