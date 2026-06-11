#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

const int N = 1e5 + 10;
string s;
int dp[N][2];

int modpow(int a, int b, int mod){
	int res = 1;
	a %= mod;
	while(b > 0){
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

int solve(int cur, int flag){
	if(cur == -1){
		return 1;
	}
	if(dp[cur][flag] != -1)
		return dp[cur][flag];
	if(flag){
		return dp[cur][flag] = modpow(3,cur+1,MOD);
	}
	int ans = 0;
	if(s[cur] == '1'){
		ans = solve(cur-1,1);
		ans += 2*solve(cur-1,0);
		ans %= MOD;
	}
	else{
		ans = solve(cur-1,0);
	}
	return dp[cur][flag] = ans;
}

//int brute(){
	//int no = 0, cur = 1;
	//for(auto x : s){
		//if(x == '1')
			//no += cur;
		//cur *= 2;
	//}
	//int ans = 0;
	//for(int i = 0; i <= no; i++){
		//for(int j = 0; j <= no; j++){
			//if(i+j <= no && (i+j) == (i^j)){
				//ans++;
			//}
		//}
	//}
	//return ans;
//}

int32_t main(){
	cin >> s;
	memset(dp,-1,sizeof dp);
	reverse(s.begin(),s.end());
	cout << solve((int)s.size()-1,0) << endl;
	
	//cout << brute() << endl;


	return 0;
}

