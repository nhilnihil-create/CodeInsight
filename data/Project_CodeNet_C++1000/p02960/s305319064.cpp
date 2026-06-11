#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define modulo 1000000007
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
string s;
ll n;
ll dp[100005][13];
ll solve(int ind, int rem){
	if(ind>=n){
		if(rem==5)
			return 1;
		return 0;
	}
	if(dp[ind][rem]!=-1)
		return dp[ind][rem];
	if(s[ind]!='?')
		return dp[ind][rem]=solve(ind+1,(10*rem+(s[ind]-'0'))%13)%modulo;
	ll res=0;
	for (int i = 0; i <= 9; ++i){
		res=(res+solve(ind+1,(10*rem+i)%13))%modulo;
	}
	dp[ind][rem]=res;
	return dp[ind][rem];
}
int main(){
	fast_io;
	cin>>s;
	n=s.length();
	memset(dp,-1,sizeof(dp));
	ll ans=solve(0,0);
	cout<<ans<<"\n";
	return 0;
}